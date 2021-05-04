#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//#include "parser.h"
#include "stack.h"
//#include "operations.h"
//#include "logica.h"
#include "token.h"
//#include "variables.h"

/*
#define MAKE_DADOS(var, TYPE, valor) \
    var.dados.TYPE = valor;          \
    var.type = TYPE;


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

char *get_delimited(char *line, char *seps, char **rest){
    char* token;
    int i;
    char* delims = " \t\n";

    while(strchr(delims,*line) != NULL && *line != '\0') line++;

    if (strlen(line) == 0 || *line == '\n') return NULL;
    
    token = (char*) malloc(strlen(line) * sizeof(char));

    strcpy(token,line);

    token++;

    for (i=0 ; (strchr(seps,token[i])) == NULL ; i++);
    
    token[i] = '\0';
    
    (*rest) = line + i;
    while ((strchr(delims,**rest) != NULL) && **rest != '\0') (*rest)++;

    line = token;
    return line;
} 

STACK *eval (char* line, STACK * s, VAR *v){
    char* seps = """[]";
    char* delims = " \t\n";
    char *tokens = "=<>!?e<e>e&e|:A:B:C:D:E:F:G:H:I:J:K:L:M:N:O:P:Q:R:S:T:U:V:W:X:Y:Z";
    char* rest[100];
    char* token = (char *) malloc(100 * sizeof(char));
    char* novaLine = (char *) malloc(100 * sizeof(char));
    char* aux[10000], aux2[10000];
    char *sobra, *sobraint;
    *rest = (char*) malloc(100 * sizeof(char));
    DATA vall;
    int i=0;
    strcpy(novaLine , line);
    strcpy(*rest , line);
    if (s == NULL) return create_stack();
    else {
         while (line != NULL){
               while (strchr(delims,*line) != NULL && *line != '\0'){
                    line++;
                    i++;
               }
               if (strchr(seps,line[i]) != NULL){
                    for (token = get_delimited(line,seps,rest); token != NULL; token = get_delimited(novaLine,seps,rest)){
                       // .......
                    }
               }
               else {
                    for (token = get_token(line,rest); token != NULL; token = get_token(novaLine,rest)){
                    DATA vall;
                    passData(line, aux);
                    long b = strtol(token, &sobraint, 10); //inteiro
                    float a = strtod(token, &sobra);       //double

                    if (strlen(sobra) == 0)
                    {
                    if (strlen(sobraint) == 0)
                    {
                    MAKE_DADOS(vall, LONG, b);
                    }
                    else
                    {
                    MAKE_DADOS(vall, DOUBLE, a);
                    }
                    push(s, vall);
                    }

                    else if (strstr(tokens, token))
                    {
                        invocaLogica(s, v, token);
                    }
                    else if (strcmp(token, "l") == 0)
                    {
                        lerlinha(aux, aux2, s, v, token);
                    }
                    else if (strlen(token) > 1)
                    {
            
                        MAKE_DADOS(vall, STRING, strdup(token));
                        push(s, vall);
                    }
            
                    else operation(s, token);
                    }
                    }
                    }
                    }        
                    }*/