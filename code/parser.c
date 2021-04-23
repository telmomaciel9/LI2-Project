/**
 * @file parser.c 
 *
 * Funções que dizem respeito ao parser.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"
#include "stack.h"
#include "operations.h"
#include "logica.h"
//#include "variables.h"

/*! 
  \brief Esta é a função que vai fazer a soma de dois valores.
  \param var Variável onde vai ficar armazenado o valor convertido.
  \param TYPE Tipo para o qual vai ser convertido o valor.
  \param valor Variável onde está guardado o valor a converter.
 */

#define MAKE_DADOS(var, TYPE, valor) \
    var.dados.TYPE = valor;          \
    var.type = TYPE;

/** 
 * \brief Esta é a função que vai fazer o parse de uma linha.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

void parse(char *line, STACK *s, VAR *v)
{
    char *token, *sobra, *sobraint;
    char *delims = " \t\n";
    char *logicaS = "=<>!?";
    char *variabS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char aux[10000], aux2[10000];
    passData(line, aux);
    for (token = strtok(line, delims); token != NULL; token = strtok(NULL, delims))
    {
        DATA vall;
        long b = strtol(token, &sobraint, 10); //inteiro
        float a = strtod(token, &sobra);       //double
        //if (a==b) MAKE_DADOS(vall,LONG,token);

        if (strlen(sobra) == 0)
        {
            if (strlen(sobraint) == 0)
            {
                MAKE_DADOS(vall, LONG, b);
            }
            else
            {
                MAKE_DADOS(vall, DOUBLE, a);
            }
            push(s, vall);
        }
        else if (strstr(logicaS,token)){
            logica(s,token);
        }
        else if (strcmp(token, "e&") == 0)
        {
            eshortcut(s);
        }
        else if (strcmp(token, "e|") == 0)
        {
            oushortcut(s);
        }
        else if (strcmp(token, "e<") == 0)
        {
            menorshortcut(s);
        }
        else if (strcmp(token, "e>") == 0)
        {
            maiorshortcut(s);
        }
        else if (strstr(variabS,token)){
            variab(s,token,v);
        }
        else if (strcmp(token, "l") == 0)
        {

            assert(fgets(aux2, 10000, stdin) != NULL);

            assert(aux2[strlen(aux2) - 1] == '\n');

            parse2(aux2, s);
            parse(strstr(aux, token) + strlen(token), s, v);
        }
        else if (strlen(token) > 1)
        {

            MAKE_DADOS(vall, STRING, strdup(token));
            push(s, vall);
        }
        else
            operation(s, token);
    }
}

/** 
 * \brief Esta é a função que vai duplicar uma string.
 * 
 * @param v String de origem.
 * 
 * @param s String para a qual vai ser copiada a original.
 *
 */

void passData(char *v, char *s)
{
    int i;
    for (i = 0; v[i] != '\0'; i++)
    {
        s[i] = v[i];
    }
    s[i] = '\0';
}

/** 
 * \brief Esta é a função que vai adicionar à stack o conteúdo de uma linha.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

void parse2(char *line, STACK *s)
{
    char *token;
    char *delims = " \t\n";
    float a;
    long b;
    char *sobra;
    char *sobraint;
    for (token = strtok(line, delims); token != NULL; token = strtok(NULL, delims))
    {
        DATA vall;
        b = strtol(token, &sobraint, 10); //inteiro
        a = strtod(token, &sobra);        //double
        //if (a==b) MAKE_DADOS(vall,LONG,token);

        if (strlen(sobra) == 0)
        {
            if (strlen(sobraint) == 0)
            {
                MAKE_DADOS(vall, LONG, b);
            }
            else
            {
                MAKE_DADOS(vall, DOUBLE, a);
            }
            push(s, vall);
        }
        else if (strlen(token) == 1)
        {

            MAKE_DADOS(vall, CHAR, *token);
            push(s, vall);
        }
        else if (strlen(token) > 1)
        {

            MAKE_DADOS(vall, STRING, strdup(token));
            push(s, vall);
        }
    }
}

/** 
 * \brief Esta é a função que vai decidir o que fazer consoante o caratere que surge no input.
 * 
 * @param token O próximo caratere a analisar.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

void operation(STACK *s, char *token)
{
    DATA vall;
    switch (*token)
    {
    case ('+'):
        soma(s);
        break;
    case ('-'):
        sub(s);
        break;
    case ('*'):
        mult(s);
        break;
    case ('/'):
        quoc(s);
        break;
    case ('('):
        dec(s);
        break;
    case (')'):
        inc(s);
        break;
    case ('%'):
        resto(s);
        break;
    case ('#'):
        expo(s);
        break;
    case ('&'):
        E(s);
        break;
    case ('|'):
        ou(s);
        break;
    case ('^'):
        xor(s);
        break;
    case ('~'):
        not(s);
        break;
    case ('_'):
        duplica(s);
        break;
    case (';'):
        pop(s);
        break;
    case ('\\'):
        swap(s);
        break;
    case ('@'):
        rotate(s);
        break;
    case ('$'):
        copy(s);
        break;
    case ('c'):
        convertChar(s);
        break;
    case ('i'):
        convertInt(s);
        break;
    case ('f'):
        convertDouble(s);
        break;
        //case ('s'):
        //    convertString(s);
        //    break;
    default:
        MAKE_DADOS(vall, CHAR, *token);
        push(s, vall);
        break;
    }
}

void variab (STACK* s, char *token, VAR* v){
    switch (*token)
    {
    case ('A'):
        encontraA(s,v);
        break;
    case ('B'):
        encontraB(s,v);
        break;
    case ('C'):
        encontraC(s,v);
        break;
    case ('D'):
        encontraD(s,v);
        break;
    case ('E'):
        encontraE(s,v);
        break;
    case ('F'):
        encontraF(s,v);
        break;
    case ('N'):
        encontraN(s,v);
        break;
    case ('S'):
        encontraS(s,v);
        break;
    case ('X'):
        encontraX(s,v);
        break;
    case ('Y'):
        encontraY(s,v);
        break;
    case ('Z'):
        encontraZ(s,v);
        break;
}
}

void logica (STACK* s, char* token){
    switch (*token)
    {
    case ('='):
        igual(s);
        break;
    case ('<'):
        menor(s);
        break;
    case ('>'):
        maior(s);
        break;
    case ('!'):
        neg(s);
        break;
    case ('?'):
        ifcond(s);
        break;
}
}

