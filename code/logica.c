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


void igual(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    long var;
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;

        if (a==b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 2))
    {
        long a = x.dados.LONG;
        long b = y.dados.DOUBLE;

        if (a==b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
    if ((descobreTipo(x) == 2) && (descobreTipo(y) == 1))
    {
        long a = x.dados.DOUBLE;
        long b = y.dados.LONG;

        if (a==b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
    if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2))
    {
        long a = x.dados.DOUBLE;
        long b = y.dados.DOUBLE;

        if (a==b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
    push(s, x);
}

void menor(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    long var;
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;

        if (a>b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 2))
    {
        long a = x.dados.LONG;
        long b = y.dados.DOUBLE;

        if (a>b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
    if ((descobreTipo(x) == 2) && (descobreTipo(y) == 1))
    {
        long a = x.dados.DOUBLE;
        long b = y.dados.LONG;

        if (a>b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
    if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2))
    {
        long a = x.dados.DOUBLE;
        long b = y.dados.DOUBLE;

        if (a>b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
    push(s,x);
}

void maior(STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    long var;
     if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;

        if (a<b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 2))
    {
        long a = x.dados.LONG;
        long b = y.dados.DOUBLE;

        if (a<b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
     if ((descobreTipo(x) == 2) && (descobreTipo(y) == 1))
    {
        long a = x.dados.DOUBLE;
        long b = y.dados.LONG;

        if (a<b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
    if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2))
    {
        long a = x.dados.DOUBLE;
        long b = y.dados.DOUBLE;

        if (a<b) var=1;
        else var=0;
        MAKE_DADOS(x,LONG,var);
    }
    push(s,x);
}

void neg(STACK *s){
    DATA x = pop(s);
    long var;
    if ((descobreTipo(x) == 1))
    {
        long a = x.dados.LONG;

        if (a==0) var=1;
        if (a==1) var=0;
        MAKE_DADOS(x,LONG,var);
    }
    push(s,x);
}