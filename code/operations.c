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
 * \brief Esta é a função que vai descobrir o tipo do elemento da stack.
 *
 * @returns 1 Caso o valor seja do tipo LONG 
 *
 * @returns 2 Caso o valor seja do tipo DOUBLE 
 *
 * @returns 3 Caso o valor seja do tipo CHAR
 * 
 * @returns 4 Caso o valor seja do tipo STRING
 *
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

int descobreTipo(DATA x)
{
    if (x.type == LONG)
        return 1;
    else if (x.type == DOUBLE)
        return 2;
    else if (x.type == CHAR)
        return 3;
    else if (x.type == STRING)
        return 4;

    return 0;
}

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
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1))
    {
        long var = x.dados.LONG + y.dados.LONG;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((descobreTipo(x) == 1) && (descobreTipo(y) == 2))
    {
        double var = x.dados.LONG + y.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 1))
    {
        double var = x.dados.DOUBLE + y.dados.LONG;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2))
    {
        double var = x.dados.DOUBLE + y.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    push(s, x);
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
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1))
    {
        long var = y.dados.LONG - x.dados.LONG;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((descobreTipo(y) == 1) && (descobreTipo(x) == 2))
    {
        double var = y.dados.LONG - x.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((descobreTipo(y) == 2) && (descobreTipo(x) == 1))
    {
        double var = y.dados.DOUBLE - x.dados.LONG;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2))
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
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1))
    {
        long var = x.dados.LONG * y.dados.LONG;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((descobreTipo(x) == 1) && (descobreTipo(y) == 2))
    {
        double var = x.dados.LONG * y.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 1))
    {
        double var = x.dados.DOUBLE * y.dados.LONG;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2))
    {
        double var = x.dados.DOUBLE * y.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    push(s, x);
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
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1))
    {
        long var = (y.dados.LONG) / (x.dados.LONG);
        MAKE_DADOS(x, LONG, var);
    }
    else if ((descobreTipo(y) == 1) && (descobreTipo(x) == 2))
    {
        double var = y.dados.LONG / x.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((descobreTipo(y) == 2) && (descobreTipo(x) == 1))
    {
        double var = y.dados.DOUBLE / x.dados.LONG;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2))
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
    if (descobreTipo(x) == 1)
    {
        long var = x.dados.LONG - 1;
        MAKE_DADOS(x, LONG, var);
    }
    else if (descobreTipo(x) == 2)
    {
        double var = x.dados.DOUBLE - 1;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if (descobreTipo(x) == 3)
    {
        char var = x.dados.CHAR - 1;
        MAKE_DADOS(x, CHAR, var);
    }
    push(s, x);
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
    if (descobreTipo(x) == 1)
    {
        long var = x.dados.LONG + 1;
        MAKE_DADOS(x, LONG, var);
    }
    else if (descobreTipo(x) == 2)
    {
        double var = x.dados.DOUBLE + 1;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if (descobreTipo(x) == 3)
    {
        char var = x.dados.CHAR + 1;
        MAKE_DADOS(x, CHAR, var);
    }
    push(s, x);
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
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1))
    {
        long var = pow(y.dados.LONG, x.dados.LONG);
        MAKE_DADOS(x, LONG, var);
    }
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 2))
    {
        double var = pow(y.dados.DOUBLE, x.dados.LONG);
        MAKE_DADOS(x, DOUBLE, var);
    }
    if ((descobreTipo(x) == 2) && (descobreTipo(y) == 1))
    {
        double var = pow(y.dados.LONG, x.dados.DOUBLE);
        MAKE_DADOS(x, DOUBLE, var);
    }
    if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2))
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
    long var = y.dados.LONG & x.dados.LONG;
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
    long var = y.dados.LONG | x.dados.LONG;
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
    long var = ~(x.dados.LONG);
    MAKE_DADOS(x, LONG, var);
    push(s, x);
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
    if (descobreTipo(x) == 1)
    {
        long var = x.dados.LONG;
        MAKE_DADOS(x, LONG, var);
    }
    else if (descobreTipo(x) == 2)
    {
        long var = x.dados.DOUBLE;
        MAKE_DADOS(x, LONG, var);
    }
    else if (descobreTipo(x) == 3)
    {
        long var = x.dados.CHAR;
        MAKE_DADOS(x, LONG, var);
    }

    else if (descobreTipo(x) == 4)
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
    if (descobreTipo(x) == 1)
    {
        double var = x.dados.LONG;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if (descobreTipo(x) == 2)
    {
        double var = x.dados.DOUBLE;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if (descobreTipo(x) == 3)
    {
        double var = x.dados.CHAR;
        MAKE_DADOS(x, DOUBLE, var);
    }
    /*
        else if (descobreTipo(x) == 4) {
            double var = x.dados.STRING;
            MAKE_DADOS(x,DOUBLE,var)
            }
        */
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
    if (descobreTipo(x) == 1)
    {
        char var = x.dados.LONG;
        MAKE_DADOS(x, CHAR, var);
    }
    else if (descobreTipo(x) == 2)
    {
        char var = x.dados.DOUBLE;
        MAKE_DADOS(x, CHAR, var);
    }
    else if (descobreTipo(x) == 3)
    {
        char var = x.dados.CHAR;
        MAKE_DADOS(x, CHAR, var);
    }
    /*
        else if (descobreTipo(x) == 4) {
            char var = x.dados.STRING;
            MAKE_DADOS(x,CHAR,var)
            }
        */
    push(s, x);
}


/*
void convertString (STACK *s){
    
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