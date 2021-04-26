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
  \brief Esta macro converte o valor para o tipo que desejamos
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
    char *tokens = "=<>!?e<e>e&e|:A:B:C:D:E:F:G:H:I:J:K:L:M:N:O:P:Q:R:S:T:U:V:W:X:Y:Z";
    char aux[10000], aux2[10000];
    passData(line, aux);
    for (token = strtok(line, delims); token != NULL; token = strtok(NULL, delims))
    {
        DATA vall;
        long b = strtol(token, &sobraint, 10); //inteiro
        float a = strtod(token, &sobra);       //double

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

        else if (strstr(tokens, token))
        {
            invocaLogica(s, v, token);
        }
        else if (strcmp(token, "l") == 0)
        {
            lerlinha(aux, aux2, s, v, token);
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

void invocaLogica(STACK *s, VAR *v, char *token)
{
    variabLogica(s, v, token);
    logica2(s, token);
    daVariab(s, v, token);
}

void lerlinha(char aux[10000], char aux2[10000], STACK *s, VAR *v, char *token)
{
    assert(fgets(aux2, 10000, stdin) != NULL);

    assert(aux2[strlen(aux2) - 1] == '\n');

    parse2(aux2, s);

    parse(strstr(aux, token) + strlen(token), s, v);
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
 * @param token O próximo caracter a analisar.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

void operation(STACK *s, char *token)
{
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
    default:
        operation2(s, token);
        break;
    }
}

void operation2(STACK *s, char *token)
{
    switch (*token)
    {
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
    default:
        operation3(s, token);
        break;
    }
}

void operation3(STACK *s, char *token)
{
    switch (*token)
    {
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
    default:
        operation4(s, token);
        break;
    }
}

void operation4(STACK *s, char *token)
{
    DATA vall;
    switch (*token)
    {
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

/** 
 * \brief Esta é a função que vai dar o valor default a cada variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 * 
 * @param v Tipo de dados que engloba todas as variáveis.
 *
 * @param token O próximo caracter a analisar.
 */

void variabLogica(STACK *s, VAR *v, char *token)
{
    switch (*token)
    {
    case ('A'):
        encontraA(s, v);
        break;
    case ('B'):
        encontraB(s, v);
        break;
    case ('C'):
        encontraC(s, v);
        break;
    case ('D'):
        encontraD(s, v);
        break;
    case ('E'):
        encontraE(s, v);
        break;
    case ('F'):
        encontraF(s, v);
        break;
    case ('N'):
        encontraN(s, v);
        break;
    case ('S'):
        encontraS(s, v);
        break;
    case ('X'):
        encontraX(s, v);
        break;
    case ('Y'):
        encontraY(s, v);
        break;
    case ('Z'):
        encontraZ(s, v);
        break;
    default:
        variabLogica2(s, token);
        break;
    }
}

void variabLogica2(STACK *s, char *token)
{
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

/** 
 * \brief Esta é a função que vai atribuir o valor pretendido a cada variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 * 
 * @param v Tipo de dados que engloba todas as variáveis.
 *
 * @param token O próximo caracter a analisar.
 */

void daVariab(STACK *s, VAR *v, char *token)
{
    auxdaVariab(s, v, token);
    aux2daVariab(s, v, token);
    aux3daVariab(s, v, token);
}

/** 
 * \brief Esta é a função que define algumas operações lógicas.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void logica(STACK *s, char *token)
{
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

/** 
 * \brief Esta é a função que define as restantes operações lógicas.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void logica2(STACK *s, char *token)
{
    if (strcmp(token, "e&") == 0)
        eshortcut(s);
    else if (strcmp(token, "e|") == 0)
        oushortcut(s);
    else if (strcmp(token, "e<") == 0)
        menorlog(s);
    else if (strcmp(token, "e>") == 0)
        maiorlog(s);
}

void auxdaVariab(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, ":A") == 0)
        daValorA(s, v);
    else if (strcmp(token, ":B") == 0)
        daValorB(s, v);
    else if (strcmp(token, ":C") == 0)
        daValorC(s, v);
    else if (strcmp(token, ":D") == 0)
        daValorD(s, v);
    else if (strcmp(token, ":E") == 0)
        daValorE(s, v);
    else if (strcmp(token, ":F") == 0)
        daValorF(s, v);
    else if (strcmp(token, ":G") == 0)
        daValorG(s, v);
    else if (strcmp(token, ":H") == 0)
        daValorH(s, v);
    else if (strcmp(token, ":I") == 0)
        daValorI(s, v);
}

void aux2daVariab(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, ":J") == 0)
        daValorJ(s, v);
    else if (strcmp(token, ":K") == 0)
        daValorK(s, v);
    else if (strcmp(token, ":L") == 0)
        daValorL(s, v);
    else if (strcmp(token, ":M") == 0)
        daValorM(s, v);
    else if (strcmp(token, ":N") == 0)
        daValorN(s, v);
    else if (strcmp(token, ":O") == 0)
        daValorO(s, v);
    else if (strcmp(token, ":P") == 0)
        daValorP(s, v);
    else if (strcmp(token, ":Q") == 0)
        daValorQ(s, v);
    else if (strcmp(token, ":R") == 0)
        daValorR(s, v);
}

void aux3daVariab(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, ":R") == 0)
        daValorR(s, v);
    else if (strcmp(token, ":S") == 0)
        daValorS(s, v);
    else if (strcmp(token, ":T") == 0)
        daValorT(s, v);
    else if (strcmp(token, ":U") == 0)
        daValorU(s, v);
    else if (strcmp(token, ":V") == 0)
        daValorV(s, v);
    else if (strcmp(token, ":W") == 0)
        daValorW(s, v);
    else if (strcmp(token, ":X") == 0)
        daValorX(s, v);
    else if (strcmp(token, ":Y") == 0)
        daValorY(s, v);
    else if (strcmp(token, ":Z") == 0)
        daValorZ(s, v);
}
