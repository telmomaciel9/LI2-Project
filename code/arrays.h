/**
 * @file arrays.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro arrays.c.
 */
#include "stack.h"

void criaArray(STACK *s);
void parseArray(STACK *s, char *line, char **rest, VAR *v);
void whiteNewSpace(STACK *s, char *token);
