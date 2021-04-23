#include "stack.h"

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
