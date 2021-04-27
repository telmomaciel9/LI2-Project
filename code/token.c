#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"
#include "stack.h"
#include "operations.h"
#include "logica.h"

/*typedef struct lista{
    int valor;
    struct lista *prox;
} *Lista;*/

char *get_token(char *line, char **rest){
     int i;  
    char* token;
    char* delims = " \t\n";
    if (strlen(line) == 0 || *line == '\n') return NULL;
    
    while(strchr(delims,*line) != NULL && *line != '\0') line++; 
    
    i=0;
    
    token = (char*) malloc(strlen(line) * sizeof(char));
    
    strcpy(token,line);
    
    for (i=0 ; (strchr(delims,token[i]) == NULL) ; i++);
    
    token[i] = '\0';
    
    (*rest) = line + i;
    while ((strchr(delims,**rest) != NULL) && **rest != '\0') (*rest)++;

    line = token;
    return line;
}