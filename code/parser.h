/**
 * @file parser.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro parser.c .
 */

#include "stack.h"

void parse (char * line);
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