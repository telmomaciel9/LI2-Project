/**
 * @file variables.c
 *
 *  Ficheiro que contem as funções que dizem respeito à parte das variáveis.
 */

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

/** 
 * \brief Esta é a função que vai dar valor default à variável A e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraA(STACK *s, VAR *v)
{
    DATA x = v->A;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável B e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraB(STACK *s, VAR *v)
{
    DATA x = v->B;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável C e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraC(STACK *s, VAR *v)
{
    DATA x = v->C;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável D e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraD(STACK *s, VAR *v)
{
    DATA x = v->D;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável E.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraE(STACK *s, VAR *v)
{
    DATA x = v->E;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável F e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraF(STACK *s, VAR *v)
{
    DATA x = v->F;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável G e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraG(STACK *s, VAR *v)
{
    DATA x = v->G;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável H e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraH(STACK *s, VAR *v)
{
    DATA x = v->H;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável I e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraI(STACK *s, VAR *v)
{
    DATA x = v->I;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável J e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraJ(STACK *s, VAR *v)
{
    DATA x = v->J;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável K e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraK(STACK *s, VAR *v)
{
    DATA x = v->K;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável L e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraL(STACK *s, VAR *v)
{
    DATA x = v->K;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável M e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraM(STACK *s, VAR *v)
{
    DATA x = v->M;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável M e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraN(STACK *s, VAR *v)
{
    DATA x = v->N;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável O e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraO(STACK *s, VAR *v)
{
    DATA x = v->O;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável P e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraP(STACK *s, VAR *v)
{
    DATA x = v->P;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável Q e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraQ(STACK *s, VAR *v)
{
    DATA x = v->Q;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável R e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraR(STACK *s, VAR *v)
{
    DATA x = v->R;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável S e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraS(STACK *s, VAR *v)
{
    DATA x = v->S;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável T e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraT(STACK *s, VAR *v)
{
    DATA x = v->T;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável U e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraU(STACK *s, VAR *v)
{
    DATA x = v->U;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável V e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraV(STACK *s, VAR *v)
{
    DATA x = v->V;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável W e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraW(STACK *s, VAR *v)
{
    DATA x = v->W;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável X e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraX(STACK *s, VAR *v)
{
    DATA x = v->X;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável Y e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraY(STACK *s, VAR *v)
{
    DATA x = v->Y;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar valor default à variável Z e faz push para a stack.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void encontraZ(STACK *s, VAR *v)
{
    DATA x = v->Z;
    push(s, x);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável A.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorA(STACK *s, VAR *v)
{
    v->A = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável B.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorB(STACK *s, VAR *v)
{
    v->B = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável C.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorC(STACK *s, VAR *v)
{
    v->C = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável D.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorD(STACK *s, VAR *v)
{
    v->D = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável E.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorE(STACK *s, VAR *v)
{
    v->E = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável F.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorF(STACK *s, VAR *v)
{
    v->F = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável G.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorG(STACK *s, VAR *v)
{
    v->G = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável H.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorH(STACK *s, VAR *v)
{
    v->H = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável I.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorI(STACK *s, VAR *v)
{
    v->I = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável J.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorJ(STACK *s, VAR *v)
{
    v->J = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável K.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorK(STACK *s, VAR *v)
{
    v->K = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável L.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorL(STACK *s, VAR *v)
{
    v->L = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável M.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorM(STACK *s, VAR *v)
{
    v->M = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável N.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorN(STACK *s, VAR *v)
{
    v->N = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável O.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorO(STACK *s, VAR *v)
{
    v->O = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável P.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorP(STACK *s, VAR *v)
{
    v->P = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável Q.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorQ(STACK *s, VAR *v)
{
    v->Q = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável R.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorR(STACK *s, VAR *v)
{
    v->R = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável S.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorS(STACK *s, VAR *v)
{
    v->S = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável T.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorT(STACK *s, VAR *v)
{
    v->T = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável U.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorU(STACK *s, VAR *v)
{
    v->U = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável V.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorV(STACK *s, VAR *v)
{
    v->V = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável W.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorW(STACK *s, VAR *v)
{
    v->W = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável X.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorX(STACK *s, VAR *v)
{
    v->X = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável Y.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorY(STACK *s, VAR *v)
{
    v->Y = top(s);
}

/** 
 * \brief Esta é a função que vai dar o valor que está no topo da stack à variável Z.
 * 
 * @param s é apontador para a stack.
 * @param v é apontador para VAR.
 *
 */

void daValorZ(STACK *s, VAR *v)
{
    v->Z = top(s);
}