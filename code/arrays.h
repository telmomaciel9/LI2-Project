/**
 * @file arrays.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro arrays.c.
 */
#include "stack.h"

/** 
 * \brief Esta é a função que cria e inicializa uma stack.
 * 
 * @param s é apontador para a stack.
 *
 */

void criaArray(STACK *s);

/** 
 * \brief Esta é a função que faz parse dos elementos da array.
 * 
 * @param s é apontador para a stack.
 *
 * @param line apontador para uma string, que armazena os tokens.
 *
 * @param rest apontador para onde se guardam as restantes strings.
 *
 * @param v apontador para um tipo var.
 *
 */

void parseArray(STACK *s, char *line, char **rest, VAR *v);

/** 
 * \brief Esta é a função que verifica os casos especiais de mudança de linha e espaço em branco.
 * 
 * @param s é apontador para a stack.
 *
 * @param token apontador para o elemento em causa, que está a ser tratado.
 */

void whiteNewSpace(STACK *s, char *token);
