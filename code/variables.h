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

