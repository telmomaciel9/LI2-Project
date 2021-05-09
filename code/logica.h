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

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma condição "maior".
 * 
 * @param s é apontador para a stack.
 *
 */

void maior(STACK *s);

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma condição "menor".
 * 
 * @param s é apontador para a stack.
 *
 */

void menor(STACK *s);

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

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma operação disjuntiva com shortcut.
 * 
 * @param s é apontador para a stack.
 *
 */

void oushortcut(STACK *s);

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante a operação lógica "menor".
 * 
 * @param s é apontador para a stack.
 *
 */

void menorlog(STACK *s);

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante a operação lógica "maior".
 * 
 * @param s é apontador para a stack.
 *
 */

void maiorlog(STACK *s);