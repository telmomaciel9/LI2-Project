/**
 * @file parser.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro parser.c .
 */

#include "stack.h"
#include "variables.h"

void parse(char *line, STACK *s, VAR *v);

void invocaLogica(STACK *s, VAR *v, char *token);

void lerlinha(char *aux2, STACK *s);

void lerlinhas(char *aux2, STACK *s);

void imprimetopo(STACK *s);

void passData(char *v, char *s);

void parse2(char *line, STACK *s, VAR *v);

void operation(STACK *s, char *token, VAR *v);

void operation2(STACK *s, char *token, VAR* v);

void operation3(STACK *s, char *token);

void operation4(STACK *s, char *token);

void daVariab(STACK *s, VAR *v, char *token);

void variabLogica(STACK *s, char *token, VAR *v);

void variabLogica2(STACK *s, char *token);

void logica2(STACK *s, char *token);

void auxdaVariab(STACK *s, VAR *v, char *token);

void aux2daVariab(STACK *s, VAR *v, char *token);

void aux3daVariab(STACK *s, VAR *v, char *token);

void aux4daVariab(STACK *s, VAR *v, char *token);

void aux5daVariab(STACK *s, VAR *v, char *token);

void aux6daVariab(STACK *s, VAR *v, char *token);

char *get_token(char *line, char **rest);

char *get_delimited(char *line, char *seps, char **rest);
