#include "stack.h"

typedef struct variables
{
   DATA A;
   DATA B;
   DATA C;
   DATA D;
   DATA E;
   DATA F;
   DATA N;
   DATA S;
   DATA X;
   DATA Y;
   DATA Z;

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
