/**
 * @file parser.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro parser.c .
 */

#include "stack.h"
#include "variables.h"

void parse(char *line, STACK *s, VAR *v);
void passData(char *v, char *s);
void parse2(char *line, STACK *s);
void operation(STACK *s, char *token);
void variab(STACK* s,char* token,VAR* v);
void logica (STACK* s, char* token);