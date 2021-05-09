/**
 * @file logica.h 
 *
 * Ficheiro que contém as declarações das operações lógicas do ficheiro logica.c.
 */

#include "stack.h"

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma condição "se".
 * 
 * @param s é apontador para a stack.
 *
 */

void ifcond(STACK *s);

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma condição "igual".
 * 
 * @param s é apontador para a stack.
 *
 */

void igual(STACK *s);
void auxIgual(STACK *s, DATA x, DATA y);
void auxIgual2(STACK *s, DATA x, DATA y);
void auxIgual3(STACK *s, DATA x, DATA y);
void auxIgual4(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma condição "maior".
 * 
 * @param s é apontador para a stack.
 *
 */

void maior(STACK *s);
void auxMaior(STACK *s, DATA x, DATA y);
void auxMaior2(STACK *s, DATA x, DATA y);
void auxMaior3(STACK *s, DATA x, DATA y);
void auxMaior4(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma condição "menor".
 * 
 * @param s é apontador para a stack.
 *
 */

void menor(STACK *s);
void auxMenor(STACK *s, DATA x, DATA y);
void auxMenor2(STACK *s, DATA x, DATA y);
void auxMenor3(STACK *s, DATA x, DATA y);
void auxMenor4(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma "negação".
 * 
 * @param s é apontador para a stack.

 */

void neg(STACK *s);

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma operação conjuntiva com shortcut.
 * 
 * @param s é apontador para a stack.
 *
 */

void eshortcut(STACK *s);
void auxeshortcut(STACK *s, DATA x, DATA y);
void auxeshortcut2(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma operação disjuntiva com shortcut.
 * 
 * @param s é apontador para a stack.
 *
 */

void oushortcut(STACK *s);
void auxoushortcut(STACK *s, DATA x, DATA y);
void auxoushortcut2(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante a operação lógica "menor".
 * 
 * @param s é apontador para a stack.
 *
 */

void menorlog(STACK *s);

void maiorlog(STACK *s);

void auxMenorLog (STACK* s,DATA x, DATA y);

void auxMenorLog2 (STACK* s,DATA x, DATA y);

void auxMaiorLog (STACK* s,DATA x, DATA y);

void auxMaiorLog2 (STACK* s,DATA x, DATA y);
