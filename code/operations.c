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
 * \brief Esta é a função que vai fazer a soma de dois valores.
 *
 * 
 *
 *
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void soma(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
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
    else if ((x.type == ARRAY && y.type == ARRAY) || (x.type == STRING && y.type == STRING) || (x.type == STRING && y.type == CHAR) || (x.type == CHAR && y.type == STRING) || (x.type == LONG && y.type == ARRAY) || (x.type == ARRAY && y.type == LONG))
    {
        STACK* u = create_stack();
        DATA t;
        MAKE_DADOS(t,ARRAY,u);
        
        push(s,x);
    }
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
    else if (x.type == LONG && y.type == ARRAY)
    {
        int i;
        for (i = 0; i < x.dados.LONG; i++)
        {
            push(s, y);
        }
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
    if ((x.type == LONG) && (y.type == LONG))
    {
        long var = (y.dados.LONG) / (x.dados.LONG);
        MAKE_DADOS(x, LONG, var);
    }
    else if ((y.type == LONG) && (x.type == DOUBLE))
    {
        double var = y.dados.LONG / x.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((y.type == DOUBLE) && (x.type == LONG))
    {
        double var = y.dados.DOUBLE / x.dados.LONG;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else
    {
        double var = y.dados.DOUBLE / x.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    push(s, x);
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
        STACK *nova2 = create_stack();
        //STACK* nova3 = create_stack();
        DATA y = top(nova);

        pop(nova);

        push(nova2, y);

        DATA p;
        MAKE_DADOS(p, ARRAY, nova2);
        push(nova, p);

        DATA t;
        MAKE_DADOS(t, ARRAY, nova);
        push(s, t);
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
    long var = y.dados.LONG % x.dados.LONG;
    MAKE_DADOS(x, LONG, var);
    push(s, x);
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
    if ((x.type == LONG) && (y.type == LONG))
    {
        long var = pow(y.dados.LONG, x.dados.LONG);
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == LONG) && (y.type == DOUBLE))
    {
        double var = pow(y.dados.DOUBLE, x.dados.LONG);
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == LONG))
    {
        double var = pow(y.dados.LONG, x.dados.DOUBLE);
        MAKE_DADOS(x, DOUBLE, var);
    }
    else
    {
        double var = pow(y.dados.DOUBLE, x.dados.DOUBLE);
        MAKE_DADOS(x, DOUBLE, var);
    }
    push(s, x);
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
    if (x.type == ARRAY)
    {
        push(s, x);
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