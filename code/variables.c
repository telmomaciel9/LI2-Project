#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

//#include "parser.h"
#include "stack.h"
//#include "logica.h"
#include "variables.h"

#define MAKE_DADOS(var, TYPE, valor) \
    var.dados.TYPE = valor;          \
    var.type = TYPE;

VAR* init_variables()
{
  VAR* var = (VAR *)calloc(1, sizeof(VAR));
  DATA a; 
  MAKE_DADOS(a,LONG,10);
  var->A = a; 
  DATA b;
  MAKE_DADOS(b,LONG,11);
  var->B = b;
  DATA c;
  MAKE_DADOS(c,LONG,12);
  var->C = c;
  DATA d;
  MAKE_DADOS(d,LONG,13);
  var->D = d;
  DATA e;
  MAKE_DADOS(e,LONG,14);
  var->E = e;
  DATA f;
  MAKE_DADOS(f,LONG,15);
  var->F = f;
  DATA n;
  MAKE_DADOS(n,CHAR,'\n');
  var->N = n;
  DATA s;
  MAKE_DADOS(s,CHAR,' ');
  var->S = s;
  DATA x;
  MAKE_DADOS(x,LONG,0);
  var->X = x;
  DATA y;
  MAKE_DADOS(y,LONG,1);
  var->Y = y;
  DATA z;
  MAKE_DADOS(z,LONG,2);
  var->Z = z;

  return var;
}

void encontraA (STACK* s,VAR* v){
    DATA x = v -> A;
    push(s,x);
}

void encontraB (STACK* s, VAR* v){
    DATA x = v -> B;
    push(s,x);
}

void encontraC (STACK* s, VAR* v){
    DATA x = v -> C;
    push(s,x);
}

void encontraD (STACK* s, VAR* v){
    DATA x = v -> D;
    push(s,x);
}

void encontraE (STACK* s,VAR* v){
    DATA x = v -> E;
    push(s,x);
}

void encontraF (STACK* s,VAR* v){
    DATA x = v -> F;
    push(s,x);
}

void encontraN (STACK* s,VAR* v){
    DATA x = v -> N;
    push(s,x);
}

void encontraS (STACK* s, VAR* v){
    DATA x = v -> S;
    push(s,x);
}

void encontraX (STACK* s,VAR* v){
    DATA x = v -> X;
    push(s,x);
}

void encontraY (STACK* s,VAR* v){
    DATA x = v -> Y;
    push(s,x);
}

void encontraZ (STACK* s,VAR* v){
    DATA x = v -> Z;
    push(s,x);
}