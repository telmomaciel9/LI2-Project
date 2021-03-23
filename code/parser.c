/**
 * @file Funções que dizem respeito ao parser.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"
#include "stack.h"


/** 
 * \brief Esta é a função que vai fazer o parse de uma linha.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @returns A stack final depois de ser feito o parse.
 */
 
void parse (char * line){
    char *token;
    char *delims = " \t\n";
    int V[10000];
    int tam= -1,i ;
    for(token = strtok (line,delims); token != NULL ; token = strtok(NULL, delims)){
        char *sobra;
        long vall = strtol(token , &sobra, 10);
        if (strlen (sobra) == 0){
            push(V,tam,10000,vall);
            tam++;
        }
        else if (strcmp (token, "+") == 0){
            long x = pop(V,tam);
            tam--;
            long y = pop(V,tam);
            tam--;
            push(V,tam,10000,x+y);
            tam++;
        }
        else if (strcmp (token, "-") == 0){
            long x = pop(V,tam);
            tam--;
            long y = pop(V,tam);
            tam--;
            push(V,tam,10000,y-x);
            tam++;
        }
        else if (strcmp (token, "*") == 0){
            long x = pop(V,tam);
            tam--;
            long y = pop(V,tam);
            tam--;
            push(V,tam,10000,x*y);
            tam++;
        }
        else if (strcmp (token, "/") == 0){
            long x = pop(V,tam);
            tam--;
            long y = pop(V,tam);
            tam--;
            push(V,tam,10000,y/x);
            tam++;
        }

        else if (strcmp (token, "(") == 0){
            long x = pop(V,tam);
            tam--;
            push(V,tam,10000, x-1);
            tam++;
        }
        else if (strcmp (token, ")") == 0){
            long x = pop(V,tam);
            tam--;
            push(V,tam,10000, x+1);
            tam++;
        }
        else if (strcmp (token, "%") == 0){
            long x = pop(V,tam);
            tam--;
            long y = pop(V,tam);
            tam--;
            push(V,tam,10000,y%x);
            tam++;
        }
        else if (strcmp (token, "#") == 0){
            long x = pop(V,tam);
            tam--;
            long y = pop(V,tam);
            tam--;
            int a,b=1;
            for (a=0;a<x;a++){
                b=b*y;
            }
            push(V,tam,10000,b);
            tam++;
        }
        else if (strcmp (token, "&") == 0){
            long x = pop(V,tam);
            tam--;
            long y = pop(V,tam);
            tam--;
            push(V,tam,10000,y&x);
            tam++;
        }
        else if (strcmp (token, "|") == 0){
            long x = pop(V,tam);
            tam--;
            long y = pop(V,tam);
            tam--;
            push(V,tam,10000,y|x);
            tam++;
        }
        else if (strcmp (token, "^") == 0){
            long x = pop(V,tam);
            tam--;
            long y = pop(V,tam);
            tam--;
            push(V,tam,10000,y^x);
            tam++;
        }
        else if (strcmp (token, "~") == 0){
            long x = pop(V,tam);
            tam--;
            push(V,tam,10000,~x);
            tam++;
        }
    }
    for (i=0;i<=tam;i++){
        printf("%d",V[i]);
    }
    putchar('\n');
}