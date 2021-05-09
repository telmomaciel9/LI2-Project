/**
 * @file logica.h 
 *
 * Ficheiro que contém as declarações das operações lógicas do ficheiro logica.c.
 */

#include "stack.h"

void ifcond(STACK *s);

void igual(STACK *s);
void auxIgual(STACK *s, DATA x, DATA y);
void auxIgual2(STACK *s, DATA x, DATA y);
void auxIgual3(STACK *s, DATA x, DATA y);
void auxIgual4(STACK *s, DATA x, DATA y);

void maior(STACK *s);
void auxMaior(STACK *s, DATA x, DATA y);
void auxMaior2(STACK *s, DATA x, DATA y);
void auxMaior3(STACK *s, DATA x, DATA y);
void auxMaior4(STACK *s, DATA x, DATA y);

void menor(STACK *s);
void auxMenor(STACK *s, DATA x, DATA y);
void auxMenor2(STACK *s, DATA x, DATA y);
void auxMenor3(STACK *s, DATA x, DATA y);
void auxMenor4(STACK *s, DATA x, DATA y);

void neg(STACK *s);

void eshortcut(STACK *s);

void oushortcut(STACK *s);

void menorlog(STACK *s);

void maiorlog(STACK *s);