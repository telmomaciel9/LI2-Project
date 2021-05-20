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
#include "arrays.h"

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
 * \brief Esta é a função que vai obter o token através do input.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @param rest aponta para uma string, que em si, é um apontador.
 *
 */

char *get_token(char *line, char **rest)
{
    int i;
    char *delims = " \t\n";
    if (strlen(line) == 0)
        return NULL;

    while (strchr(delims, *line) != NULL && *line != '\0')
        line++;

    if (strlen(line) == 0 || *line == '\n')
        return NULL;

    char *token;

    token = (char *)malloc((strlen(line) + 1) * sizeof(char));

    strcpy(token, line);

    for (i = 0; (strchr(delims, token[i]) == NULL); i++)
        ;

    token[i] = '\0';

    (*rest) = line + i;
    while ((strchr(delims, **rest) != NULL) && **rest != '\0')
        (*rest)++;

    line = token;
    return line;
}

/** 
 * \brief Esta é a função que vai obter o token através do input.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @param seps apontador para uma lista de caracteres.
 *
 * @param rest aponta para uma string, que em si, é um apontador.
 *
 */

char *get_delimited(char *line, char *seps, char **rest)
{
    char *token;
    int i;
    char *delims = " \t\n";

    while (strchr(delims, *line) != NULL && *line != '\0')
    {
        line++;
    }

    if (strlen(line) == 0 || *line == '\n')
        return NULL;

    token = (char *)malloc((strlen(line) + 1) * sizeof(char));

    strcpy(token, line);

    token++;

    //printf("%s\n",token);

    for (i = 0; (strchr(seps, token[i])) == NULL; i++)
        ;

    token[i] = '\0';

    (*rest) = line + i + 2;
    while ((strchr(delims, **rest) != NULL) && **rest != '\0')
        (*rest)++;

    //token = token + 2;
    line = token;
    return line;
}

/** 
 * \brief Esta é a função que vai fazer a leitura de uma linha.
 *
 * @param line apontador para um linha.
 * @param seps apontador para uma lista de caracteres.
 * @param rest aponta para uma string, que em si, é um apontador.
 */

char *get_delimited_bloco(char *line, char *seps, char **rest)
{
    char *token;
    int i;
    char *delims = " \t\n";

    while (strchr(delims, *line) != NULL && *line != '\0')
    {
        line++;
    }

    if (strlen(line) == 0 || *line == '\n')
        return NULL;

    token = (char *)malloc((strlen(line) + 1) * sizeof(char));

    strcpy(token, line);

    //token++;

    //printf("%s",token);

    for (i = 0; (strchr(seps, token[i])) == NULL; i++)
        ;

    i++;

    token[i] = '\0';

    (*rest) = line + i + 1;
    while ((strchr(delims, **rest) != NULL) && **rest != '\0')
        (*rest)++;

    //token = token + 2;
    line = token;
    return line;
}

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
    char *seps = "\"";
    char *seps2 = "}";
    char *tokens = "=<>!?:A:B:C:D:E:F:G:H:I:J:K:L:M:N:O:P:Q:R:S:T:U:V:W:X:Y:Z";
    char *rest[100];
    char *token = (char *)malloc((strlen(line) + 1) * sizeof(char));
    char *novaLine = (char *)malloc((strlen(line) + 1) * sizeof(char));
    *rest = (char *)malloc((strlen(line) + 1) * sizeof(char));
    char aux2[3000];
    strcpy(novaLine, line);
    strcpy(*rest, line);
    strcpy(token, line);
    //passData(line, aux);
    for (token = get_token(line, rest); token != NULL; token = get_token(novaLine, rest))
    {

        DATA vall;

        char *sobra;
        char *sobraint;

        long b = strtol(token, &sobraint, 10); //inteiro
        float a = strtod(token, &sobra);       //double

        if ((strcmp(token, "[") == 0))
        {
            parseArray(s, novaLine, rest, v);
        }
        else if (*token == '\"')
        {
            char *a = get_delimited(novaLine, seps, rest);
            DATA t;
            MAKE_DADOS(t, STRING, a);
            push(s, t);
        }
        else if (*token == '{')
        {
            char *b = get_delimited_bloco(novaLine, seps2, rest);
            DATA t;
            MAKE_DADOS(t, BLOCO, b);
            push(s, t);
        }
        else if (strlen(sobra) == 0)
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
        else if ((strcmp(token, "l") == 0) || (strcmp(token, "t") == 0) || (strcmp(token, "p") == 0) || (strcmp(token, "S/") == 0) || (strcmp(token, "N/") == 0) || (strcmp(token, ",") == 0))
        {
            lerlinha(aux2, s, token);
            whiteNewSpace(s, token);
            handle_ahritmetic(token, s, v);
        }
        else if (strstr(tokens, token))
        {
            invocaLogica(s, v, token);
        }
        else if (strlen(token) == 1)
        {
            operation(s, token, v);
        }
        else if (strcmp(token, "e&") == 0 || strcmp(token, "e|") == 0 || strcmp(token, "e<") == 0 || strcmp(token, "e>") == 0)
        {
            logica2(s, token);
        }
        else if (strlen(token) > 1)
        {
            MAKE_DADOS(vall, STRING, strdup(token));
            push(s, vall);
        }
        // printf("%s\n", token);
        novaLine = *rest;
    }
}

/** 
 * \brief Esta é a função que vai fazer as operações lógicas e de variáveis.
 * 
 * @param s Apontador para a stack.
 * @param v Apontador para VAR.
 * @param token Zona onde vão ser guardados os tokens. 
 */

void invocaLogica(STACK *s, VAR *v, char *token)
{
    variabLogica(s, token, v);
    daVariab(s, v, token);
}

/** 
 * \brief Esta é a função que vai fazer a leitura de uma linha.
 *
 * @param aux Cópia da line.
 * @param aux2 Zona onde vão ser guardados os tokens da linha que se vai ler.
 * @param s Apontador para a stack.
 * @param v Apontador para VAR.
 * @param token Zona onde vão ser guardados os tokens. 
 */

void lerlinha(char *aux2, STACK *s, char *token)
{
    if (strcmp(token, "l") == 0)
    {
        assert(fgets(aux2, 10000, stdin) != NULL);

        assert(aux2[strlen(aux2) - 1] == '\n');

        // parse2(aux2, s, v);

        DATA a;
        MAKE_DADOS(a, STRING, aux2);
        push(s, a);
    }

    else if (strcmp(token, "t") == 0)
    {
        char linha1[10000];
        //linha1 = (char *)malloc(100 * sizeof(char));
        while (fgets(aux2, 10000, stdin) != NULL)
        {
            strcpy(strlen(linha1) + linha1, aux2);
        }
        assert(linha1[strlen(linha1) - 1] == '\n');
        DATA a;
        MAKE_DADOS(a, STRING, linha1);
        push(s, a);
    }
    else if (strcmp(token, "p") == 0)
    {
        DATA x = top(s);
        TYPE type = x.type;
        switch (type)
        {
        case LONG:
            printf("%ld", x.dados.LONG);
            break;
        case DOUBLE:
            printf("%g", x.dados.DOUBLE);
            break;
        case CHAR:
            printf("%c", x.dados.CHAR);
            break;
        case STRING:
            printf("%s", x.dados.STRING);
            break;
        case ARRAY:
            print_stack(x.dados.ARRAY);
            break;
        case BLOCO:
            printf("%s", x.dados.BLOCO);
            break;
        }
        putchar('\n');
    }
}

/** 
 * \brief Esta é a função que vai fazer a leitura de várias linhas.
 *
 * @param aux2 Zona onde vão ser guardados os tokens da linha que se vai ler.
 * @param s Apontador para a stack.
 * 
 */

/*void lerlinhas(char *aux2, STACK *s)
{
    char linha1[10000];
    //linha1 = (char *)malloc(100 * sizeof(char));
    while (fgets(aux2, 10000, stdin) != NULL)
    {
        strcpy(strlen(linha1) + linha1, aux2);
    }
    assert(linha1[strlen(linha1) - 1] == '\n');
    DATA a;
    MAKE_DADOS(a, STRING, linha1);
    push(s, a);
}*/

/** 
 * \brief Esta é a função que imprime o topo da stack.
 *
 * @param s Apontador para a stack.
 * 
 */

/*void imprimetopo(STACK *s)
{
    DATA x = top(s);
    TYPE type = x.type;
    switch (type)
    {
    case LONG:
        printf("%ld", x.dados.LONG);
        break;
    case DOUBLE:
        printf("%g", x.dados.DOUBLE);
        break;
    case CHAR:
        printf("%c", x.dados.CHAR);
        break;
    case STRING:
        printf("%s", x.dados.STRING);
        break;
    case ARRAY:
        print_stack(x.dados.ARRAY);
        break;
    case BLOCO:
        printf("%s", x.dados.BLOCO);
        break;
    }
    putchar('\n');
}*/

/** 
 * \brief Esta é a função que vai decidir o que fazer consoante o caratere que surge no input.
 * 
 * @param token O próximo caracter a analisar.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

void operation(STACK *s, char *token, VAR *v)
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
        handle_ahritmetic(token, s, v);
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
        handle_ahritmetic(token, s, v);
        break;
    case ('#'):
        expo(s);
        break;
    default:
        operation2(s, token, v);
        break;
    }
}

/** 
 * \brief Esta é a função que vai decidir a operação a fazer.
 * 
 * @param token O próximo caracter a analisar.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

void operation2(STACK *s, char *token, VAR *v)
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
        handle_ahritmetic(token, s, v);
        break;
    default:
        operation3(s, token);
        break;
    }
}

/** 
 * \brief Esta é a função que vai decidir a operação a fazer.
 * 
 * @param token O próximo caracter a analisar.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

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

/** 
 * \brief Esta é a função que vai converter tipos.
 * 
 * @param token O próximo caracter a analisar.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

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

void variabLogica(STACK *s, char *token, VAR *v)
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
    case ('G'):
        encontraG(s, v);
        break;
    case ('H'):
        encontraH(s, v);
        break;
    case ('I'):
        encontraI(s, v);
        break;
    case ('J'):
        encontraJ(s, v);
        break;
    case ('K'):
        encontraK(s, v);
        break;
    case ('L'):
        encontraL(s, v);
        break;
    case ('M'):
        encontraM(s, v);
        break;
    case ('N'):
        encontraN(s, v);
        break;
    case ('O'):
        encontraO(s, v);
        break;
    case ('P'):
        encontraP(s, v);
        break;
    case ('Q'):
        encontraQ(s, v);
        break;
    case ('R'):
        encontraR(s, v);
        break;
    case ('S'):
        encontraS(s, v);
        break;
    case ('T'):
        encontraT(s, v);
        break;
    case ('U'):
        encontraU(s, v);
        break;
    case ('V'):
        encontraV(s, v);
        break;
    case ('W'):
        encontraW(s, v);
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

/** 
 * \brief Esta é a função que vai decidir a operação lógica a fazer.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

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
    aux4daVariab(s, v, token);
    aux5daVariab(s, v, token);
    aux6daVariab(s, v, token);
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

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

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
}

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void aux2daVariab(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, ":F") == 0)
        daValorF(s, v);
    else if (strcmp(token, ":G") == 0)
        daValorG(s, v);
    else if (strcmp(token, ":H") == 0)
        daValorH(s, v);
    else if (strcmp(token, ":I") == 0)
        daValorI(s, v);
}

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void aux3daVariab(STACK *s, VAR *v, char *token)
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
}

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void aux4daVariab(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, ":O") == 0)
        daValorO(s, v);
    else if (strcmp(token, ":P") == 0)
        daValorP(s, v);
    else if (strcmp(token, ":Q") == 0)
        daValorQ(s, v);
    else if (strcmp(token, ":R") == 0)
        daValorR(s, v);
}

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void aux5daVariab(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, ":S") == 0)
        daValorS(s, v);
    else if (strcmp(token, ":T") == 0)
        daValorT(s, v);
    else if (strcmp(token, ":U") == 0)
        daValorU(s, v);
    else if (strcmp(token, ":V") == 0)
        daValorV(s, v);
}

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void aux6daVariab(STACK *s, VAR *v, char *token)
{
    if (strcmp(token, ":W") == 0)
        daValorW(s, v);
    else if (strcmp(token, ":X") == 0)
        daValorX(s, v);
    else if (strcmp(token, ":Y") == 0)
        daValorY(s, v);
    else if (strcmp(token, ":Z") == 0)
        daValorZ(s, v);
}