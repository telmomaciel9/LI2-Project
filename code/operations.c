/**
 * @file operations.c
 * 
 * Ficheiro que contém funções que dizem respeito às operações (lógicas, matemáticas, conversões e manipulação da stack)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "parser.h"
#include "stack.h"
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
 * \brief Esta é a função, auxiliar, que vai fazer a soma de dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxSoma4(STACK *s, DATA x, DATA y)
{
    if (x.type == CHAR && y.type == STRING)
    {
        char *a = strncat(y.dados.STRING, &x.dados.CHAR, 1);
        DATA t;
        MAKE_DADOS(t, STRING, a);
        push(s, t);
    }
    else if (x.type == STRING && y.type == CHAR)
    {
        char *a = (char *)malloc((strlen(x.dados.STRING) * sizeof(char *)));
        a[0] = y.dados.CHAR;
        strcpy(a + 1, x.dados.STRING);
        DATA t;
        MAKE_DADOS(t, STRING, a);
        push(s, t);
    }
}

/** 
 * \brief Esta é a função, auxiliar, que vai fazer a soma de dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxSoma3(STACK *s, DATA x, DATA y)
{
    if (x.type == ARRAY && y.type == LONG)
    {
        STACK *u = create_stack();
        int i = 0;
        int lengthX = x.dados.ARRAY->n_elems;
        x.dados.ARRAY->n_elems = 1;
        DATA t;
        MAKE_DADOS(t, LONG, y.dados.LONG);
        push(u, t);

        for (i = 0; i < lengthX; i++)
        {
            push(u, top(x.dados.ARRAY));
            x.dados.ARRAY->n_elems++;
        }

        MAKE_DADOS(x, ARRAY, u);
        push(s, x);
    }
    else if (x.type == LONG && y.type == ARRAY)
    {
        STACK *u = create_stack();
        int i = 0;
        int lengthY = y.dados.ARRAY->n_elems;
        y.dados.ARRAY->n_elems = 1;

        for (i = 0; i < lengthY; i++)
        {
            push(u, top(y.dados.ARRAY));
            y.dados.ARRAY->n_elems++;
        }

        DATA t;
        MAKE_DADOS(t, LONG, x.dados.LONG);
        push(u, t);

        MAKE_DADOS(x, ARRAY, u);
        push(s, x);
    }
    else if (x.type == ARRAY && y.type == CHAR)
    {
        STACK *u = create_stack();

        DATA t;
        MAKE_DADOS(t, CHAR, y.dados.CHAR);
        push(u, t);

        DATA v;
        MAKE_DADOS(v, ARRAY, x.dados.ARRAY);
        push(u, v);

        MAKE_DADOS(x, ARRAY, u);
        push(s, x);
    }
    else if (x.type == STRING && y.type == STRING)
    {
        char *a = strcat(y.dados.STRING, x.dados.STRING);
        DATA t;
        MAKE_DADOS(t, STRING, a);
        push(s, t);
    }
}

/** 
 * \brief Esta é a função, auxiliar, que vai fazer a soma de dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxSoma2(STACK *s, DATA x, DATA y)
{
    if (x.type == LONG && y.type == CHAR)
    {
        char var = x.dados.LONG + y.dados.CHAR;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    else if (x.type == CHAR && y.type == LONG)
    {
        char var = x.dados.CHAR + y.dados.LONG;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    else if (x.type == CHAR && y.type == CHAR)
    {
        char var = x.dados.CHAR + y.dados.CHAR;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    else if (x.type == ARRAY && y.type == ARRAY)
    {
        STACK *u = create_stack();
        int i = 0;
        int lengthX = x.dados.ARRAY->n_elems;
        int lengthY = y.dados.ARRAY->n_elems;
        y.dados.ARRAY->n_elems = 1;
        x.dados.ARRAY->n_elems = 1;
        for (i = 0; i < lengthY; i++)
        {
            push(u, top(y.dados.ARRAY));
            y.dados.ARRAY->n_elems++;
        }
        for (i = 0; i < lengthX; i++)
        {
            push(u, top(x.dados.ARRAY));
            x.dados.ARRAY->n_elems++;
        }
        MAKE_DADOS(x, ARRAY, u);
        push(s, x);
    }
}

/** 
 * \brief Esta é a função, auxiliar, que vai fazer a soma de dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxSoma(STACK *s, DATA x, DATA y)
{
    if (x.type == LONG && y.type == LONG)
    {
        long var = x.dados.LONG + y.dados.LONG;
        MAKE_DADOS(x, LONG, var);
        push(s, x);
    }
    else if (x.type == LONG && y.type == DOUBLE)
    {
        double var = x.dados.LONG + y.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
    else if (x.type == DOUBLE && y.type == LONG)
    {
        double var = x.dados.DOUBLE + y.dados.LONG;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
    else if (x.type == DOUBLE && y.type == DOUBLE)
    {
        double var = x.dados.DOUBLE + y.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
}

/** 
 * \brief Esta é a função que vai fazer a soma de dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void soma(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    auxSoma(s, x, y);
    auxSoma2(s, x, y);
    auxSoma3(s, x, y);
    auxSoma4(s, x, y);
}

/** 
 * \brief Esta é a função que vai fazer a subtração de dois valores.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 */

void sub(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    if ((x.type == LONG) && (y.type == LONG))
    {
        long var = y.dados.LONG - x.dados.LONG;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((y.type == LONG) && (x.type == DOUBLE))
    {
        double var = y.dados.LONG - x.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((y.type == DOUBLE) && (x.type == LONG))
    {
        double var = y.dados.DOUBLE - x.dados.LONG;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else
    {
        double var = y.dados.DOUBLE - x.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    push(s, x);
}

/** 
 * \brief Esta é a função,auxiliar, que multiplica dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxMult(STACK *s, DATA x, DATA y)
{
    if ((x.type == LONG) && (y.type == LONG))
    {
        long var = x.dados.LONG * y.dados.LONG;
        MAKE_DADOS(x, LONG, var);
        push(s, x);
    }
    else if ((x.type == LONG) && (y.type == DOUBLE))
    {
        double var = x.dados.LONG * y.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
    else if ((x.type == DOUBLE) && (y.type == LONG))
    {
        double var = x.dados.DOUBLE * y.dados.LONG;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
    else if ((x.type == DOUBLE) && (y.type == DOUBLE))
    {
        double var = x.dados.DOUBLE * y.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
}

/** 
 * \brief Esta é a função, auxiliar, que multiplica dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxMult2(STACK *s, DATA x, DATA y)
{
    if ((x.type == CHAR) && (y.type == LONG))
    {
        char var = x.dados.CHAR * y.dados.LONG;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    else if ((x.type == LONG) && (y.type == CHAR))
    {
        char var = x.dados.LONG * y.dados.CHAR;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    else if ((x.type == CHAR) && (y.type == CHAR))
    {
        char var = x.dados.CHAR * y.dados.CHAR;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
}

/** 
 * \brief Esta é a função, auxiliar, que multiplica dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxMult3(STACK *s, DATA x, DATA y){
 if (y.type == ARRAY)
    {
        int i;
        STACK *nova = create_stack();
        STACK *a = y.dados.ARRAY;
        int length = a->n_elems;
        for (i = 0; i < x.dados.LONG; i++)
        {
            a->n_elems = 1;
            while (a->n_elems != length + 1)
            {
                push(nova, pop(a));
                a->n_elems += 2;
            }
            a->n_elems += 2;
        }
        y.dados.ARRAY = nova;
        MAKE_DADOS(x, ARRAY, y.dados.ARRAY);
        push(s, x);
    }
    else if (y.type == STRING)
    {
        int i;
        char *a;
        a = (char *)malloc(sizeof(char *) * (strlen(y.dados.STRING) * x.dados.LONG));
        //int b = strlen(y.dados.STRING);
        for (i = 0; i < x.dados.LONG; i++)
        {
            strcat(a, y.dados.STRING);
        }
        //*a = '\0';
        MAKE_DADOS(x, STRING, a);
        push(s, x);
    }
}

/** 
 * \brief Esta é a função que multiplica dois valores.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void mult(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    auxMult(s, x, y);
    auxMult2(s, x, y);
    auxMult3(s, x, y);
}

/** 
 * \brief Esta é a função, auxiliar, que divide dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxQuoc(STACK *s, DATA x, DATA y)
{
    if ((x.type == LONG) && (y.type == LONG))
    {
        long var = (y.dados.LONG) / (x.dados.LONG);
        MAKE_DADOS(x, LONG, var);
        push(s, x);
    }
    else if ((y.type == LONG) && (x.type == DOUBLE))
    {
        double var = y.dados.LONG / x.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
    else if ((y.type == DOUBLE) && (x.type == LONG))
    {
        double var = y.dados.DOUBLE / x.dados.LONG;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
    else if ((y.type == DOUBLE) && (x.type == DOUBLE))
    {
        double var = y.dados.DOUBLE / x.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
}

/** 
 * \brief Esta é a função, auxiliar, que divide dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxQuoc2(STACK *s, DATA x, DATA y)
{
    if ((y.type == CHAR) && (x.type == CHAR))
    {
        char var = y.dados.CHAR / x.dados.CHAR;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    else if ((y.type == LONG) && (x.type == CHAR))
    {
        char var = y.dados.LONG / x.dados.CHAR;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
    else if ((y.type == CHAR) && (x.type == LONG))
    {
        char var = y.dados.CHAR / x.dados.LONG;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    else if ((y.type == STRING) && (x.type == STRING))
    {
        char *a;
        STACK *t = create_stack();
        a = strtok(y.dados.STRING, x.dados.STRING);
        DATA b;
        while (a != NULL)
        {

            MAKE_DADOS(b, STRING, a);
            push(t, b);
            a = strtok(NULL, x.dados.STRING);
        }
        DATA c;
        MAKE_DADOS(c, ARRAY, t);
        push(s, c);
    }
}

/** 
 * \brief Esta é a função que divide dois valores um pelo outro.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void quoc(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    auxQuoc(s, x, y);
    auxQuoc2(s, x, y);
}

/** 
 * \brief Esta é a função é responsável por decrementar 1 valor.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void dec(STACK *s)
{
    DATA x = pop(s);
    if (x.type == LONG)
    {
        long var = x.dados.LONG - 1;
        MAKE_DADOS(x, LONG, var);
        push(s, x);
    }
    else if (x.type == DOUBLE)
    {
        double var = x.dados.DOUBLE - 1;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
    else if (x.type == CHAR)
    {
        char var = x.dados.CHAR - 1;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    else if (x.type == ARRAY)
    {
        STACK *nova = x.dados.ARRAY;
        STACK *nova2 = create_stack();

        int length = nova->n_elems;
        int i = 2;

        while (i <= length)
        {
            nova->n_elems = i;
            push(nova2, pop(nova));
            i++;
        }

        DATA p;
        MAKE_DADOS(p, ARRAY, nova2);
        push(s, p);
        nova->n_elems = 1;
        push(s, pop(nova));
    }
    else if (x.type == STRING)
    {
        char a = *x.dados.STRING;
        x.dados.STRING = x.dados.STRING + 1;
        DATA t;
        MAKE_DADOS(t, STRING, x.dados.STRING)
        push(s, t);
        MAKE_DADOS(x, CHAR, a);
        push(s, x);
    }
}

/** 
 * \brief Esta é a função responsável por incrementar 1 valor.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void inc(STACK *s)
{
    DATA x = pop(s);
    if (x.type == 1)
    {
        long var = x.dados.LONG + 1;
        MAKE_DADOS(x, LONG, var);
        push(s, x);
    }
    else if (x.type == DOUBLE)
    {
        double var = x.dados.DOUBLE + 1;
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
    else if (x.type == CHAR)
    {
        char var = x.dados.CHAR + 1;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    else if (x.type == ARRAY)
    {

        STACK *nova = x.dados.ARRAY;

        DATA y = pop(nova);

        push(s, x);
        push(s, y);
    }
    else if (x.type == STRING)
    {
        int i;
        for (i = 0; x.dados.STRING[i] != '\0'; i++)
            ;
        char a = x.dados.STRING[i - 1];
        x.dados.STRING[i - 1] = '\0';
        DATA t;
        MAKE_DADOS(t, STRING, x.dados.STRING);
        push(s, t);
        MAKE_DADOS(x, CHAR, a);
        push(s, x);
    }
}

/** 
 * \brief Esta é a função que vai apresentar o resto da divisão.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void resto(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    if ((x.type == LONG) && (y.type == LONG))
    {
        long var = y.dados.LONG % x.dados.LONG;
        MAKE_DADOS(x, LONG, var);
        push(s, x);
    }
    else if ((x.type == LONG) && (y.type == CHAR))
    {
        char var = y.dados.CHAR % x.dados.LONG;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    else if ((x.type == CHAR) && (y.type == LONG))
    {
        char var = y.dados.LONG % x.dados.CHAR;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    else if ((x.type == CHAR) && (y.type == CHAR))
    {
        char var = y.dados.CHAR % x.dados.CHAR;
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
}

/** 
 * \brief Esta é a uma das funções auxiliares para a função Expo.
 *
 * 
 * @param x Onde vai ser armazenado o valor e o seu respetivo tipo
 * 
 * @param y Onde vai ser armazenado o valor e o seu respetivo tipo
 *
 */

void auxExpo(STACK* s,DATA x, DATA y){
    if ((x.type == LONG) && (y.type == LONG))
    {
        long var = pow(y.dados.LONG, x.dados.LONG);
        MAKE_DADOS(x, LONG, var);
        push(s, x);
    }
    else if ((x.type == LONG) && (y.type == DOUBLE))
    {
        double var = pow(y.dados.DOUBLE, x.dados.LONG);
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
    else if ((x.type == DOUBLE) && (y.type == LONG))
    {
        double var = pow(y.dados.LONG, x.dados.DOUBLE);
        MAKE_DADOS(x, DOUBLE, var);
        push(s, x);
    }
    else if ((x.type == DOUBLE) && (y.type == DOUBLE))
    {
        double var = pow(y.dados.DOUBLE, x.dados.DOUBLE);
        MAKE_DADOS(x, DOUBLE, var);
        push(s,x);
    }
}

/** 
 * \brief Esta é a uma das funções auxiliares para a função Expo.
 *
 * 
 * @param x Onde vai ser armazenado o valor e o seu respetivo tipo
 * 
 * @param y Onde vai ser armazenado o valor e o seu respetivo tipo
 *
 */

void auxExpo2 (STACK* s, DATA x,DATA y){
    if ((x.type == LONG) && (y.type == CHAR))
    {
        char var = pow(y.dados.CHAR, x.dados.LONG);
        MAKE_DADOS(x, CHAR, var);
        push(s,x);
    }
    else if ((x.type == STRING) && (y.type == STRING))
    {
        int i = 0;
        if (strstr(y.dados.STRING, x.dados.STRING) == NULL)
            i = -1;
        else
        {
            char *serprocurado = x.dados.STRING;
            char *procura = y.dados.STRING;
            char *c = strstr(procura, serprocurado);

            while (c != procura && *procura != '\0')
            {
                procura++;
                i++;
            }
        }
        MAKE_DADOS(x, LONG, i);
        push(s, x);
    } 
}

/** 
 * \brief Esta é a função responsável pela exponencialização de valores.
 * 
 *
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void expo(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    auxExpo(s,x,y);
    auxExpo2(s,x,y);
}

/** 
 * \brief Função que realiza operações do 'e' lógico (bitwise) para inteiros.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void E(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    long var = (y.dados.LONG & x.dados.LONG);
    MAKE_DADOS(x, LONG, var);
    push(s, x);
}

/** 
 * \brief Função que realiza operações do 'ou' lógico (bitwise) para inteiros.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void ou(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    long var = (y.dados.LONG | x.dados.LONG);
    MAKE_DADOS(x, LONG, var);
    push(s, x);
}

/** 
 * \brief Função que realiza operações xor (bitwise) para inteiros.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void xor (STACK * s) {
    DATA x = pop(s);
    DATA y = pop(s);
    long var = y.dados.LONG ^ x.dados.LONG;
    MAKE_DADOS(x, LONG, var);
    push(s, x);
}

/**
* \brief Função que realiza operações not (bitwise) para inteiros.
*
*
* @param s Stack onde vão ser armazenados os valores.
*
*/

void not(STACK * s)
{
    DATA x = pop(s);
    if (x.type == LONG)
    {
        long var = ~(x.dados.LONG);
        MAKE_DADOS(x, LONG, var);
        push(s, x);
    }
    if (x.type == CHAR)
    {
        char var = ~(x.dados.CHAR);
        MAKE_DADOS(x, CHAR, var);
        push(s, x);
    }
    if (x.type == ARRAY)
    {
        int i = 0;
        int b = x.dados.ARRAY->n_elems;
        STACK *nova = x.dados.ARRAY;
        while (i < b)
        {
            nova->n_elems = i + 1;
            DATA c = pop(nova);
            push(s, c);
            i++;
        }
    }
}

/** 
 * \brief Função que converte o valor do topo da stack para inteiro.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void convertInt(STACK *s)
{
    DATA x = pop(s);
    if (x.type == LONG)
    {
        long var = x.dados.LONG;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == DOUBLE)
    {
        long var = x.dados.DOUBLE;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == CHAR)
    {
        long var = x.dados.CHAR;
        MAKE_DADOS(x, LONG, var);
    }
    else
    {
        char *eptr;
        long result = strtol(x.dados.STRING, &eptr, 10);
        MAKE_DADOS(x, LONG, result);
    }

    push(s, x);
}

/** 
 * \brief Função que converte o valor do topo da stack para double.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void convertDouble(STACK *s)
{
    DATA x = pop(s);
    if (x.type == LONG)
    {
        double var = x.dados.LONG;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if (x.type == DOUBLE)
    {
        double var = x.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if (x.type == CHAR)
    {
        double var = x.dados.CHAR;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else
    {
        char *eptr;
        double result = strtod(x.dados.STRING, &eptr);
        MAKE_DADOS(x, DOUBLE, result);
    }
    push(s, x);
}

/** 
 * \brief Função que converte o valor do topo da stack para caractere.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void convertChar(STACK *s)
{
    DATA x = pop(s);
    if (x.type == LONG)
    {
        char var = x.dados.LONG;
        MAKE_DADOS(x, CHAR, var);
    }
    else if (x.type == DOUBLE)
    {
        char var = x.dados.DOUBLE;
        MAKE_DADOS(x, CHAR, var);
    }
    else if (x.type == CHAR)
    {
        char var = x.dados.CHAR;
        MAKE_DADOS(x, CHAR, var);
    }
    /*
        else if (x.type == 4) {
            char var = x.dados.STRING;
            MAKE_DADOS(x,CHAR,var)
            }
        */
    push(s, x);
}

/*
void convertString(STACK *s)
{
    char *sx;
    DATA x = pop(s);
    if (x.type == LONG)
    {
        string var = ltoa(x.dados.LONG, sx, 10);
        MAKE_DADOS(x, STRING, var);
    }
    else if (x.type == DOUBLE)
    {
        sprintf(sx, "%f", x.dados.DOUBLE);
        MAKE_DADOS(x, STRING, sx);
    }
    else if (x.type == CHAR)
    {
        long var = x.dados.CHAR;
        MAKE_DADOS(x, LONG, var);
        string var = ltoa(x.dados.LONG, sx, 10);
        MAKE_DADOS(x, STRING, var);
    }
    else
    {
        string var = x.dados.STRING;
        MAKE_DADOS(x, STRING, var);
    }
    push(s, x);
}
*/

/** 
 * \brief Função que troca os últimos 2 elementos da stack.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void swap(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    push(s, x);
    push(s, y);
}

/** 
 * \brief Função que roda os últimos 3 elementos da stack.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void rotate(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    DATA z = pop(s);
    push(s, y);
    push(s, x);
    push(s, z);
}

/** 
 * \brief Função que copia o n-ésimo elemento para o topo da stack.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void copy(STACK *s)
{
    DATA x = pop(s);
    long var = x.dados.LONG;
    DATA y = obterElemento(s, var);
    push(s, y);
}

/** 
 * \brief Função que duplica o último elemento da stack.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void duplica(STACK *s)
{
    DATA y = top(s);
    push(s, y);
}

/** 
 * \brief Função que executa o que está dentro do bloco.
 * 
 * @param s apontador para a stack.
 * 
 * @param v apontador para uma variável.
 *
 */

void executaBloco(STACK *s, VAR *v)
{
    DATA x = pop(s);
    DATA y = pop(s);
    if (x.type == BLOCO)
    {
        x.dados.BLOCO++;
        char *aux1 = (char *)malloc(sizeof(char) * strlen(x.dados.BLOCO));
        STACK *aux = create_stack();
        int a = strlen(x.dados.BLOCO);

        strcpy(aux1, x.dados.BLOCO);
        aux1[a - 2] = '\0';

        push(aux, y);

        parse(aux1, aux, v);

        //print_stack(aux);

        MAKE_DADOS(x, ARRAY, aux);
        push(s, x);
    }
}

/** 
 * \brief Função que faz o map.
 * 
 * @param s apontador para a stack.
 * 
 * @param v apontador para uma variável.
 *
 */

void aplicaArrays(STACK *s, VAR *v)
{
    DATA x = pop(s); // x é bloco
    DATA y = pop(s); // y é array
    int i;
    if (x.type == BLOCO && y.type == ARRAY)
    {
        x.dados.BLOCO++;
        char *aux1 = (char *)malloc(sizeof(char) * strlen(x.dados.BLOCO));
        STACK *aux = create_stack();
        strcpy(aux1, x.dados.BLOCO);
        int a = strlen(x.dados.BLOCO);
        aux1[a - 2] = '\0';
        int b = y.dados.ARRAY->n_elems;
        y.dados.ARRAY->n_elems = 1;
        for (i = 0; i < b; i++)
        {
            DATA t = top(y.dados.ARRAY);
            push(aux, t);
            //print_stack(aux);
            // printf("\n");
            //printf("%s",x.dados.BLOCO);
            parse(aux1, aux, v);
            y.dados.ARRAY->n_elems++;
        }
        MAKE_DADOS(x, ARRAY, aux);
        push(s, x);
    }
    else if (x.type == BLOCO && y.type == STRING)
    {
        x.dados.BLOCO++;
        int a = strlen(x.dados.BLOCO);
        char *aux1 = (char *)malloc(sizeof(char) * strlen(x.dados.BLOCO));
        //char* aux2 = (char *) malloc(sizeof(char) * strlen(y.dados.STRING));
        strcpy(aux1, x.dados.BLOCO);
        aux1[a - 2] = '\0';
        int c = strlen(y.dados.STRING);
        for (i = 0; i < c; i++)
        {
            DATA t;
            STACK *s1 = create_stack();
            MAKE_DADOS(t, CHAR, y.dados.STRING[i]);
            push(s1, t);
            parse(aux1, s1, v);
            if (top(s1).type == CHAR)
            {
                y.dados.STRING[i] = top(s1).dados.LONG;
                //printf("%c",y.dados.STRING[i]);
            }
        }
        y.dados.STRING[i] = '\0';
        MAKE_DADOS(x, STRING, y.dados.STRING);
        push(s, x);
    }
}

/**
 * \brief Função que dada um bloco, faz uma filter da stack.
 * 
 * @param s apontador para a stack.
 *
 * @param v apontador para VAR.
 */

void filter(STACK *s, VAR *v)
{
    DATA x = pop(s);
    DATA y = pop(s);
    int i;
    if (x.type == BLOCO && y.type == ARRAY)
    {
        x.dados.BLOCO++;
        STACK *aux = create_stack();
        STACK *aux2 = create_stack();
        char *aux1 = (char *)malloc(sizeof(char) * strlen(x.dados.BLOCO));
        strcpy(aux1, x.dados.BLOCO);
        int a = strlen(x.dados.BLOCO);
        aux1[a - 2] = '\0';
        int b = y.dados.ARRAY->n_elems;
        y.dados.ARRAY->n_elems = 1;
        for (i = 0; i < b; i++)
        {
            DATA t = top(y.dados.ARRAY);
            push(aux, t);
            parse(aux1, aux, v);
            if (aux->stack[i].dados.LONG == 1)
            {
                push(aux2, t);
                //printf("%ld\n",aux->stack[d].dados.LONG);
            }
            y.dados.ARRAY->n_elems++;
        }
        MAKE_DADOS(x, ARRAY, aux2);
        push(s, x);
    }
    if (x.type == BLOCO && y.type == STRING)
    {
        x.dados.BLOCO++;
        int a = strlen(x.dados.BLOCO);
        char *aux1 = (char *)malloc(sizeof(char) * strlen(x.dados.BLOCO));
        strcpy(aux1, x.dados.BLOCO);
        aux1[a - 2] = '\0';
        int k = 0;
        int c = strlen(y.dados.STRING);
        //printf("%d",c);
        for (i = 0; i < c; i++)
        {
            STACK *s1 = create_stack();
            DATA t;
            MAKE_DADOS(t, CHAR, y.dados.STRING[i]);
            //printf ("%c\n",y.dados.STRING[i]);
            push(s1, t);
            parse(aux1, s1, v);
            if (top(s1).dados.LONG)
            {
                y.dados.STRING[k] = y.dados.STRING[i];
                k++;
            }
        }
        y.dados.STRING[k] = '\0';
        push(s, y);
    }
}

/** 
 * \brief Esta é a função que vai fazer fold de um array.
 *
 * @param s Stack onde vão ser armazenados os valores.
 * 
 * @param x Onde vai ser armazenado o valor e o seu respetivo tipo
 * 
 * @param y Onde vai ser armazenado o valor e o seu respetivo tipo
 *
 */

void fold(STACK *s, VAR *v)
{
    DATA x = pop(s);
    DATA y = pop(s);
    if (x.type == BLOCO && y.type == ARRAY)
    {
        x.dados.BLOCO++;
        int i;
        int a = strlen(x.dados.BLOCO);
        char *aux1 = (char *)malloc(sizeof(char) * strlen(x.dados.BLOCO));
        STACK *aux = create_stack();
        strcpy(aux1, x.dados.BLOCO);
        aux1[a - 2] = '\0';
        int tam = y.dados.ARRAY->n_elems;
        push(aux, y.dados.ARRAY->stack[0]);
        for (i = 0; i < tam; i++)
        {
            push(aux, y.dados.ARRAY->stack[i]);
            parse(aux1, aux, v);
        }
        y.dados.ARRAY = aux;
        push(s, y);
    }
}

/*void executaBlocoTruthy (STACK *s, VAR *v){
    DATA x = top(s);
    //DATA y = pop(s);
    if (x.type == BLOCO){
    executaBloco(s,v);
    while (pop(s).dados.LONG){
           push(s,x);
           executaBloco(s,v);
    }
  }      
}*/

/**
 * \brief Função que decide a operação a ser feita consoante o tipo do elemento.
 * 
 * 
 * @param token Elemento pertencente à stack que vai ser tratado.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 * 
 * @param v Apontador para uma variável.
 * 
 */

void handle_ahritmetic(char *token, STACK *s, VAR *v)
{
    DATA x = top(s);
    if (x.type == BLOCO)
    {
        //DATA y = pop(s);
        switch (*token)
        {
        case ('~'):
            executaBloco(s, v);
            break;
        case ('%'):
            aplicaArrays(s, v);
            break;
        case (','):
            filter(s, v);
            break;
        case ('*'):
            fold(s, v);
            break; 
        }
    }
    else
    {
        switch (*token)
        {
        case ('~'):
            not(s);
            break;
        case ('%'):
            resto(s);
            break;
        case (','):
            criaArray(s);
            break;
        case ('*'):
            mult(s);
            break;
        }
    }
}
