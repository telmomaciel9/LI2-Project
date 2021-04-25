#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "parser.h"
#include "stack.h"
#include "logica.h"

#define MAKE_DADOS(var, TYPE, valor) \
    var.dados.TYPE = valor;          \
    var.type = TYPE;

void ifcond(STACK *s)
{
    switch (s->n_elems)
    {
    case (0):
        break;
    case (1):
        break;
    case (2):
    {
        DATA x = pop(s);
        push(s, x);
        break;
    }
    default:
    {
        DATA x = pop(s);
        DATA y = pop(s);
        DATA z = pop(s);
        if (z.dados.LONG == 0)
            push(s, x);
        else
            push(s, y);
        break;
    }
    }
}

void igual(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    long var;
    if ((x.type == LONG && y.type == LONG) || (x.type == DOUBLE && y.type == DOUBLE))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;
        if (a == b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == LONG && y.type == DOUBLE)
    {
        long a = x.dados.LONG;
        double b = y.dados.DOUBLE;
        if (a == b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == DOUBLE && y.type == LONG)
    {
        double a = x.dados.DOUBLE;
        long b = y.dados.LONG;
        if (a == b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == LONG && y.type == CHAR) || (x.type == CHAR && y.type == LONG) || (x.type == CHAR && y.type == CHAR)){
        double a = x.dados.DOUBLE;
        double b = y.dados.DOUBLE;
        if (a == b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == DOUBLE && y.type == CHAR){
        double a = x.dados.DOUBLE;
        char b = y.dados.CHAR;
        if (a == b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == CHAR && y.type == DOUBLE){
        char a = x.dados.CHAR;
        double b = y.dados.DOUBLE;
        if (a == b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    push(s, x);
}

void maior(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    long var;
    if ((x.type == LONG && y.type == LONG) || (x.type == DOUBLE && y.type == DOUBLE))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;
        if (a < b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == LONG && y.type == DOUBLE)
    {
        long a = x.dados.LONG;
        double b = y.dados.DOUBLE;
        if (a < b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == DOUBLE && y.type == LONG)
    {
        double a = x.dados.DOUBLE;
        long b = y.dados.LONG;
        if (a < b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == LONG && y.type == CHAR) || (x.type == CHAR && y.type == LONG) || (x.type == CHAR && y.type == CHAR)){
        double a = x.dados.DOUBLE;
        double b = y.dados.DOUBLE;
        if (a < b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == DOUBLE && y.type == CHAR){
        double a = x.dados.DOUBLE;
        char b = y.dados.CHAR;
        if (a < b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == CHAR && y.type == DOUBLE){
        char a = x.dados.CHAR;
        double b = y.dados.DOUBLE;
        if (a < b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    push(s, x);
}

void menor(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    long var;
    if ((x.type == LONG && y.type == LONG) || (x.type == DOUBLE && y.type == DOUBLE))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;
        if (a > b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == LONG && y.type == DOUBLE)
    {
        long a = x.dados.LONG;
        double b = y.dados.DOUBLE;
        if (a > b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == DOUBLE && y.type == LONG)
    {
        double a = x.dados.DOUBLE;
        long b = y.dados.LONG;
        if (a > b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == LONG && y.type == CHAR) || (x.type == CHAR && y.type == LONG) || (x.type == CHAR && y.type == CHAR)){
        double a = x.dados.DOUBLE;
        double b = y.dados.DOUBLE;
        if (a > b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == DOUBLE && y.type == CHAR){
        double a = x.dados.DOUBLE;
        char b = y.dados.CHAR;
        if (a > b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if (x.type == CHAR && y.type == DOUBLE){
        char a = x.dados.CHAR;
        double b = y.dados.DOUBLE;
        if (a > b)
            var = 1;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    push(s, x);
}

void neg(STACK *s)
{
    DATA x = pop(s);
    long var;
    long a = x.dados.LONG;
    if (a == 1)
        var = 0;
    if (a == 0)
        var = 1;
    MAKE_DADOS(x, LONG, var)
    push(s, x);
}

void eshortcut(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    double var;
    if ((x.type == LONG) && (y.type == LONG))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;
        if (b != 0)
            var = a;
        else
            var = 0;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == LONG) && (y.type == DOUBLE))
    {
        long a = x.dados.LONG;
        double b = y.dados.DOUBLE;
        if (b != 0)
            var = a;
        else
            var = 0;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == LONG))
    {
        double a = x.dados.DOUBLE;
        long b = y.dados.LONG;
        if (b != 0)
            var = a;
        else
            var = 0;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == DOUBLE))
    {
        double a = x.dados.DOUBLE;
        double b = y.dados.DOUBLE;
        if (b != 0)
            var = a;
        else
            var = 0;
        MAKE_DADOS(x, DOUBLE, var);
    }
    push(s, x);
}

void oushortcut(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    double var;
    if ((x.type == LONG) && (y.type == LONG))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;
        if (b == 0)
            var = a;
        else
            var = b;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == LONG) && (y.type == DOUBLE))
    {
        long a = x.dados.LONG;
        double b = y.dados.DOUBLE;
        if (b == 0)
            var = a;
        else
            var = b;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == DOUBLE) && (y.type == LONG))
    {
        double a = x.dados.DOUBLE;
        long b = y.dados.LONG;
        if (b == 0)
            var = a;
        else
            var = b;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == DOUBLE))
    {
        double a = x.dados.DOUBLE;
        double b = y.dados.DOUBLE;
        if (b == 0)
            var = a;
        else
            var = b;
        MAKE_DADOS(x, DOUBLE, var);
    }
    push(s, x);
}

void menorshortcut(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    double var;
    if ((x.type == LONG) && (y.type == LONG))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;
        if (b < a)
            var = b;
        else
            var = a;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == LONG) && (y.type == DOUBLE))
    {
        long a = x.dados.LONG;
        double b = y.dados.DOUBLE;
        if (b < a)
            var = b;
        else
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == LONG))
    {
        double a = x.dados.DOUBLE;
        long b = y.dados.LONG;
        if (b < a)
            var = b;
        else
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == DOUBLE))
    {
        double a = x.dados.DOUBLE;
        double b = y.dados.DOUBLE;
        if (b < a)
            var = b;
        else
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    push(s, x);
}

void maiorshortcut(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    double var;
    if ((x.type == LONG) && (y.type == LONG))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;
        if (b > a)
            var = b;
        else
            var = a;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == LONG) && (y.type == DOUBLE))
    {
        long a = x.dados.LONG;
        double b = y.dados.DOUBLE;
        if (b > a)
            var = b;
        else
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == LONG))
    {
        double a = x.dados.DOUBLE;
        long b = y.dados.LONG;
        if (b > a)
            var = b;
        else
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == DOUBLE))
    {
        double a = x.dados.DOUBLE;
        double b = y.dados.DOUBLE;
        if (b > a)
            var = b;
        else
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    push(s, x);
}