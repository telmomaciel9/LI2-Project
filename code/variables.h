/**
 * @file variables.h 
 *
 * Ficheiro que contém as declarações das funções e da struct variables do ficheiro variables.c.
 */

#include "stack.h"

/** @struct variables
 *  @brief Esta struct serve para armazenar as variáveis.
 *  @var variables::A
 *  @var variables::B
 *  @var variables::C
 *  @var variables::D
 *  @var variables::E
 *  @var variables::F
 *  @var variables::G
 *  @var variables::H
 *  @var variables::I
 *  @var variables::J
 *  @var variables::K
 *  @var variables::L
 *  @var variables::M
 *  @var variables::N
 *  @var variables::O
 *  @var variables::P
 *  @var variables::Q
 *  @var variables::R
 *  @var variables::S
 *  @var variables::T
 *  @var variables::U
 *  @var variables::V
 *  @var variables::W
 *  @var variables::X
 *  @var variables::Y
 *  @var variables::Z
 */

typedef struct variables
{
   DATA A;DATA B;DATA C;DATA D;
   DATA E;DATA F;DATA G;DATA H;
   DATA I;DATA J;DATA K;DATA L;
   DATA M;DATA N;DATA O;DATA P;
   DATA Q;DATA R;DATA S;DATA T;
   DATA U;DATA V;DATA W;DATA X;
   DATA Y;DATA Z;
} VAR;

VAR* init_variables();
void encontraA (STACK* s,VAR* v);
void encontraB (STACK* s,VAR* v);
void encontraC (STACK* s,VAR* v);
void encontraD (STACK* s,VAR* v);
void encontraE (STACK* s,VAR* v);
void encontraF (STACK* s,VAR* v);
void encontraN (STACK* s,VAR* v);
void encontraS (STACK* s,VAR* v);
void encontraX (STACK* s,VAR* v);
void encontraY (STACK* s,VAR* v);
void encontraZ (STACK* s,VAR* v);
void daValorA (STACK* s,VAR* v);
void daValorB (STACK* s,VAR* v);
void daValorC (STACK* s,VAR* v);
void daValorD (STACK* s,VAR* v);
void daValorE (STACK* s,VAR* v);
void daValorF (STACK* s,VAR* v);
void daValorG (STACK* s,VAR* v);
void daValorH (STACK* s,VAR* v);
void daValorI (STACK* s,VAR* v);
void daValorJ (STACK* s,VAR* v);
void daValorK (STACK* s,VAR* v);
void daValorL (STACK* s,VAR* v);
void daValorM (STACK* s,VAR* v);
void daValorN (STACK* s,VAR* v);
void daValorO (STACK* s,VAR* v);
void daValorP (STACK* s,VAR* v);
void daValorQ (STACK* s,VAR* v);
void daValorR (STACK* s,VAR* v);
void daValorS (STACK* s,VAR* v);
void daValorT (STACK* s,VAR* v);
void daValorU (STACK* s,VAR* v);
void daValorV (STACK* s,VAR* v);
void daValorW (STACK* s,VAR* v);
void daValorX (STACK* s,VAR* v);
void daValorY (STACK* s,VAR* v);
void daValorZ (STACK* s,VAR* v);