/**
 * @file parser.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro parser.c .
 */

#include "stack.h"
#include "variables.h"

void parse(char *line, STACK *s, VAR *v);
void invocaLogica(STACK *s, VAR *v, char *token);
void lerlinha(char aux[10000], char aux2[10000], STACK *s, VAR *v, char *token);
void passData(char *v, char *s);
void parse2(char *line, STACK *s);
void operation(STACK *s, char *token);
void operation2(STACK *s, char *token);
void operation3(STACK *s, char *token);
void operation4(STACK *s, char *token);
void daVariab(STACK *s, VAR *v, char *token);
void variabLogica(STACK *s, VAR *v, char *token);
void variabLogica2(STACK *s, char *token);
void logica2(STACK *s, char *token);
void auxdaVariab(STACK *s, VAR *v, char *token);
void aux2daVariab(STACK *s, VAR *v, char *token);
void aux3daVariab(STACK *s, VAR *v, char *token);
void aux4daVariab(STACK *s, VAR *v, char *token);
void aux5daVariab(STACK *s, VAR *v, char *token);
void aux6daVariab(STACK *s, VAR *v, char *token);
