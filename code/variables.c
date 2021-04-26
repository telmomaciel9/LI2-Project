#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "stack.h"
#include "variables.h"

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
 * \brief Esta é a função que vai inicializar o valor de algumas variáveis.
 *
 */

VAR *init_variables()
{
    VAR *var = (VAR *)calloc(1, sizeof(VAR));
    DATA a;
    MAKE_DADOS(a, LONG, 10);
    var->A = a;
    DATA b;
    MAKE_DADOS(b, LONG, 11);
    var->B = b;
    DATA c;
    MAKE_DADOS(c, LONG, 12);
    var->C = c;
    DATA d;
    MAKE_DADOS(d, LONG, 13);
    var->D = d;
    DATA e;
    MAKE_DADOS(e, LONG, 14);
    var->E = e;
    DATA f;
    MAKE_DADOS(f, LONG, 15);
    var->F = f;
    DATA n;
    MAKE_DADOS(n, CHAR, '\n');
    var->N = n;
    DATA s;
    MAKE_DADOS(s, CHAR, ' ');
    var->S = s;
    DATA x;
    MAKE_DADOS(x, LONG, 0);
    var->X = x;
    DATA y;
    MAKE_DADOS(y, LONG, 1);
    var->Y = y;
    DATA z;
    MAKE_DADOS(z, LONG, 2);
    var->Z = z;

    return var;
}

void encontraA(STACK *s, VAR *v)
{
    DATA x = v->A;
    push(s, x);
}

void encontraB(STACK *s, VAR *v)
{
    DATA x = v->B;
    push(s, x);
}

void encontraC(STACK *s, VAR *v)
{
    DATA x = v->C;
    push(s, x);
}

void encontraD(STACK *s, VAR *v)
{
    DATA x = v->D;
    push(s, x);
}

void encontraE(STACK *s, VAR *v)
{
    DATA x = v->E;
    push(s, x);
}

void encontraF(STACK *s, VAR *v)
{
    DATA x = v->F;
    push(s, x);
}

void encontraN(STACK *s, VAR *v)
{
    DATA x = v->N;
    push(s, x);
}

void encontraS(STACK *s, VAR *v)
{
    DATA x = v->S;
    push(s, x);
}

void encontraX(STACK *s, VAR *v)
{
    DATA x = v->X;
    push(s, x);
}

void encontraY(STACK *s, VAR *v)
{
    DATA x = v->Y;
    push(s, x);
}

void encontraZ(STACK *s, VAR *v)
{
    DATA x = v->Z;
    push(s, x);
}

void daValorA(STACK *s, VAR *v)
{
    v->A = top(s);
}

void daValorB(STACK *s, VAR *v)
{
    v->B = top(s);
}

void daValorC(STACK *s, VAR *v)
{
    v->C = top(s);
}

void daValorD(STACK *s, VAR *v)
{
    v->D = top(s);
}

void daValorE(STACK *s, VAR *v)
{
    v->E = top(s);
}

void daValorF(STACK *s, VAR *v)
{
    v->F = top(s);
}

void daValorG(STACK *s, VAR *v)
{
    v->G = top(s);
}

void daValorH(STACK *s, VAR *v)
{
    v->H = top(s);
}

void daValorI(STACK *s, VAR *v)
{
    v->I = top(s);
}

void daValorJ(STACK *s, VAR *v)
{
    v->J = top(s);
}

void daValorK(STACK *s, VAR *v)
{
    v->K = top(s);
}

void daValorL(STACK *s, VAR *v)
{
    v->L = top(s);
}

void daValorM(STACK *s, VAR *v)
{
    v->M = top(s);
}

void daValorN(STACK *s, VAR *v)
{
    v->N = top(s);
}

void daValorO(STACK *s, VAR *v)
{
    v->O = top(s);
}

void daValorP(STACK *s, VAR *v)
{
    v->P = top(s);
}

void daValorQ(STACK *s, VAR *v)
{
    v->Q = top(s);
}

void daValorR(STACK *s, VAR *v)
{
    v->R = top(s);
}

void daValorS(STACK *s, VAR *v)
{
    v->S = top(s);
}

void daValorT(STACK *s, VAR *v)
{
    v->T = top(s);
}

void daValorU(STACK *s, VAR *v)
{
    v->U = top(s);
}

void daValorV(STACK *s, VAR *v)
{
    v->V = top(s);
}

void daValorW(STACK *s, VAR *v)
{
    v->W = top(s);
}

void daValorX(STACK *s, VAR *v)
{
    v->X = top(s);
}

void daValorY(STACK *s, VAR *v)
{
    v->Y = top(s);
}

void daValorZ(STACK *s, VAR *v)
{
    v->Z = top(s);
}