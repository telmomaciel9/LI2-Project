/**
 * @file parser.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro parser.c .
 */

#include "stack.h"

void parse(char *line, STACK *s);
void passData(char *v, char *s);
void parse2(char *line, STACK *s);
void operation(STACK *s, char *token);