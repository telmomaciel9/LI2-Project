/**
 * @file parser.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro parser.c .
 */

#include "stack.h"

void parse (char * line, STACK* s);
void soma (STACK *s);
void sub (STACK *s);
void mult (STACK *s);
void quoc (STACK *s);
void E (STACK *s);
void not (STACK *s);
void xor (STACK *s);
void ou (STACK *s);
void dec (STACK *s);
void inc (STACK *s);
void resto (STACK *s);
void expo (STACK *s);
void convertInt (STACK *s);
void convertChar (STACK *s);
void convertDouble (STACK *s);
//void convertString (STACK *s);
void passData (char* v, char* s);
void parse2 (char* line, STACK* s);