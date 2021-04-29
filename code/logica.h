/**
 * @file logica.h 
 *
 * Ficheiro que contém as declarações das operações lógicas do ficheiro logica.c.
 */

#include "stack.h"

void ifcond(STACK *s);

void igual(STACK *s, char * line ,VAR * v);

void maior(STACK *s);

void menor(STACK *s);

void neg(STACK *s);

void eshortcut(STACK *s);

void oushortcut(STACK *s);

void menorlog(STACK *s);

void maiorlog(STACK *s);