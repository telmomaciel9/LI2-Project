/**
 * @file parser.c 
 *
 * Funções que dizem respeito ao parser.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"
#include "stack.h"
#include "stack.c"


/** 
 * \brief Esta é a função que vai fazer o parse de uma linha.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @returns A stack final depois de ser feito o parse.
 */

#define MAKE_DADOS(var, TIPO, valor)                 \
        var.dados.TIPO = valor;                      \
        var.type = TIPO;

/*
int comp (char s[]){
    int i,cont;
    for(i=0; s[i]!='\0'; i++){
        cont++;
    }
    return comp;
}
*/

void parse (char * line){
    STACK* s = create_stack();
    char *token;
    char *delims = " \t\n";
    float a;
    long b;
    for(token = strtok (line,delims); token != NULL ; token = strtok(NULL, delims)){
        char *sobra;
        DATA vall;
        b = strtol(token,&sobra,10);
        a = strtod(token,&sobra);
        if (a==b) MAKE_DADOS(vall,LONG,token);
        if (strlen(sobra) == 0){
            if (a==b){ 
                MAKE_DADOS(vall,LONG,a);
            }
            else if (a!=b) {
                MAKE_DADOS(vall,DOUBLE,a);
                }

            push(s,vall);
        }
        else if (strlen(token)==1) {

            MAKE_DADOS(vall,CHAR,*token);
            push(s,vall);
        }
        else {  

            MAKE_DADOS(vall,STRING,strdup(token));
            push(s,vall);
        }
       /* if (strcmp (token, "+") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            x.dados.DOUBLE = x.dados.DOUBLE + y.dados.DOUBLE;
            MAKE_DADOS(x,DOUBLE,*token);
            push(s,x);
        }*/
    }    
    print_stack(s);

    //putchar('\n');
}

/*char *sobra;
        long vall = strtol(token , &sobra, 10);
        if (strlen (sobra) == 0){
            push(vall);
        }
        else if (strcmp (token, "+") == 0){
            long x = pop();
            long y = pop();
            push(x+y);
        }
        else if (strcmp (token, "-") == 0){
            long x = pop();
            long y = pop();
            push(y-x);
        }
        else if (strcmp (token, "*") == 0){
            long x = pop();
            long y = pop();
            push(x*y);
        }
        else if (strcmp (token, "/") == 0){
            long x = pop();
            long y = pop();
            push(y/x);
        }
        else if (strcmp (token, "(") == 0){
            long x = pop();
            push(x-1);
        }
        else if (strcmp (token, ")") == 0){
            long x = pop();
            push(x+1);
        }
        else if (strcmp (token, "%") == 0){
            long x = pop();
            long y = pop();
            push(y%x);
        }
        else if (strcmp (token, "#") == 0){
            long x = pop();
            long y = pop();
            int a,b=1;
            for (a=0;a<x;a++){
                b=b*y;
            }
            push(b);
        }
        else if (strcmp (token, "&") == 0){
            long x = pop();
            long y = pop();
            push(y&x);
        }
        else if (strcmp (token, "|") == 0){
            long x = pop();
            long y = pop();
            push(y|x);
        }
        else if (strcmp (token, "^") == 0){
            long x = pop();
            long y = pop();
            push(y^x);
        }
        else if (strcmp (token, "~") == 0){
            long x = pop();
            push(~x);
        }*/