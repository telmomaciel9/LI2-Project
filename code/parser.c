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

#define MAKE_DADOS(var, TYPE, valor)                 \
        var.dados.TYPE = valor;                      \
        var.type = TYPE;

/** 
 * \brief Esta é a função que vai fazer o parse de uma linha.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @returns A stack final depois de ser feito o parse.
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
        //if (a==b) MAKE_DADOS(vall,LONG,token);
        if (strlen(sobra) == 0){
            if (a==b){ 
                MAKE_DADOS(vall,LONG,b);
            }
            else if (a!=b) {
                MAKE_DADOS(vall,DOUBLE,a);
                }

            push(s,vall);
        }
        else if (strcmp (token, "+") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            long var = x.dados.LONG + y.dados.LONG;
            MAKE_DADOS(x,LONG,var);
            push(s,x);
        }
        else if (strcmp (token, "-") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            long var = y.dados.LONG - x.dados.LONG;
            MAKE_DADOS(x,LONG,var);
            push(s,x);
        }
        else if (strcmp (token, "*") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            long var = x.dados.LONG * y.dados.LONG;
            MAKE_DADOS(x,LONG,var);
            push(s,x);
        }
        else if (strcmp (token, "/") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            long var = y.dados.LONG / x.dados.LONG ;
            MAKE_DADOS(x,LONG,var);
            push(s,x);
        }
        else if (strcmp (token, "(") == 0){
            DATA x = pop(s);
            long var = x.dados.LONG - 1 ;
            MAKE_DADOS(x,LONG,var);
            push(s,x);
        }
        else if (strcmp (token, ")") == 0){
            DATA x = pop(s);
            long var = x.dados.LONG + 1;
            MAKE_DADOS(x,LONG,var);
            push(s,x);
        }
        else if (strcmp (token, "%") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            long var = y.dados.LONG % x.dados.LONG;
            MAKE_DADOS(x,LONG,var);
            push(s,x);
        }
        else if (strcmp (token, "#") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            long a,b=1;
            for (a=0;a<(x.dados.LONG);a++){
                b=b*(y.dados.LONG);
            }
            MAKE_DADOS(x,LONG,b);
            push(s,x);
        }
        else if (strcmp (token, "&") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            long var = y.dados.LONG & x.dados.LONG;
            MAKE_DADOS(x,LONG,var);
            push(s,x);
        }
        else if (strcmp (token, "|") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            long var = y.dados.LONG | x.dados.LONG;
            MAKE_DADOS(x,LONG,var);
            push(s,x);
        }
        else if (strcmp (token, "^") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            long var = y.dados.LONG ^ x.dados.LONG;
            MAKE_DADOS(x,LONG,var);
            push(s,x);
        }
        else if (strcmp (token, "~") == 0){
            DATA x = pop(s);
            long var = ~(x.dados.LONG);
            MAKE_DADOS(x,LONG,var);
            push(s,x);
        }
        else if (strcmp (token, "_") == 0){
            DATA y = top(s);
            push(s,y);
        }
        else if (strcmp (token, ";") == 0){
             pop(s);
        }
        else if (strcmp (token, "\\") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            push(s,x);
            push(s,y);
        }
        else if (strcmp (token, "@") == 0){
            DATA x = pop(s);
            DATA y = pop(s);
            DATA z = pop(s);
            push(s,y);
            push(s,x);
            push(s,z);
        }
        else if (strcmp (token, "c") == 0) {

            DATA x = pop(s);
            char var = x.dados.CHAR;
            MAKE_DADOS(x,CHAR,var);
            push(s,x);

        }
        
        else if (strcmp (token, "i") == 0) {

            DATA x = pop(s);
            long var = x.dados.LONG;
            MAKE_DADOS(x,LONG,var);
            push(s,x);
            
        }
        
        else if (strcmp (token, "f") == 0) {

            DATA x = pop(s);
            double var = x.dados.DOUBLE;
            MAKE_DADOS(x,DOUBLE,var);
            push(s,x);
            
        }
        /*
        else if (strcmp (token, "s") == 0) {

            DATA x = pop(s);
            char * var = x.dados.STRING;
            MAKE_DADOS(x,STRING,var);
            push(s,x);
            
        }
        */
        else if (strlen(token)==1) {

            MAKE_DADOS(vall,CHAR,*token);
            push(s,vall);
        }
        else if (strlen(token)>1){  

            MAKE_DADOS(vall,STRING,strdup(token));
            push(s,vall);
        }
    }    
    print_stack(s);
}
