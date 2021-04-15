#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "parser.h"
#include "stack.h"

#define MAKE_DADOS(var, TYPE, valor) \
    var.dados.TYPE = valor;          \
    var.type = TYPE;

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

void resto(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    long var = y.dados.LONG % x.dados.LONG;
    MAKE_DADOS(x, LONG, var);
    push(s, x);
}

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

void E(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    long var = y.dados.LONG & x.dados.LONG;
    MAKE_DADOS(x, LONG, var);
    push(s, x);
}

void ou(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    long var = y.dados.LONG | x.dados.LONG;
    MAKE_DADOS(x, LONG, var);
    push(s, x);
}

void xor (STACK * s) {
    DATA x = pop(s);
    DATA y = pop(s);
    long var = y.dados.LONG ^ x.dados.LONG;
    MAKE_DADOS(x, LONG, var);
    push(s, x);
}

    void not(STACK * s)
{
    DATA x = pop(s);
    long var = ~(x.dados.LONG);
    MAKE_DADOS(x, LONG, var);
    push(s, x);
}

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

void swap(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    push(s, x);
    push(s, y);
}

void rotate(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    DATA z = pop(s);
    push(s, y);
    push(s, x);
    push(s, z);
}

void copy(STACK *s)
{
    DATA x = pop(s);
    long var = x.dados.LONG;
    DATA y = obterElemento(s, var);
    push(s, y);
}

void duplica(STACK *s)
{
    DATA y = top(s);
    push(s, y);
}