/**
 * @file parser.c 
 *
 * Funções que dizem respeito ao parser.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

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

int descobreTipo (DATA x){
    if (x.type == LONG) return 1;  
    else if (x.type == DOUBLE) return 2;
    else if (x.type == CHAR) return 3;
    else if (x.type == STRING) return 4;
    
    return 0;
}

void parse (char * line){
    STACK *s = create_stack();
    char *token;
    char *delims = " \t\n";
    float a;
    long b;
    char *sobra;
    char *sobraint;
    for(token = strtok (line,delims); token != NULL ; token = strtok(NULL, delims)){
        DATA vall;
        b = strtol(token,&sobraint,10); //inteiro
        a = strtod(token,&sobra);    //double
        //if (a==b) MAKE_DADOS(vall,LONG,token);
        
        if (strlen(sobra) == 0){
            if (strlen(sobraint) == 0) { 
                MAKE_DADOS(vall,LONG,b);
            }
            else{
                MAKE_DADOS(vall,DOUBLE,a);
                }
            push(s,vall);
        }
        
        else if (strcmp (token, "+") == 0){
            soma(s);
        }
        else if (strcmp (token, "-") == 0){
            sub(s);
        }
        else if (strcmp (token, "*") == 0){
            mult(s);
        }
        else if (strcmp (token, "/") == 0){
            quoc(s);
        }
        else if (strcmp (token, "(") == 0){
            dec(s);
        }
        else if (strcmp (token, ")") == 0){
            inc(s);
        }
        else if (strcmp (token, "%") == 0){
            resto(s);
        }
        else if (strcmp (token, "#") == 0){
            expo(s);
        }
        else if (strcmp (token, "&") == 0){
            E(s);
        }
        else if (strcmp (token, "|") == 0){
            ou(s);
        }
        else if (strcmp (token, "^") == 0){
            xor(s);
        }
        else if (strcmp (token, "~") == 0){
            not(s);
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
            convertChar (s);
        }
        
        else if (strcmp (token, "i") == 0) {
            convertInt (s);
        }
        
        else if (strcmp (token, "f") == 0) {
            convertDouble (s);
        }
        /*
        else if (strcmp (token, "s") == 0) {

            DATA x = pop(s);
            char * var = x.dados.STRING;
            MAKE_DADOS(x,STRING,var);
            push(s,x);
            
        }
        */
        else if (strcmp (token, "l") == 0){
            char l [10000];

            assert( fgets (l ,10000,stdin) != NULL);

            assert ( l [strlen (l) - 1] == '\n'   );
            parse(l);

        }
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


void soma (STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1)) {
         long var = x.dados.LONG + y.dados.LONG;
         MAKE_DADOS(x,LONG,var);
    }
    else if ((descobreTipo(x) == 1) && (descobreTipo(y) == 2)) {
        double var = x.dados.LONG + y.dados.DOUBLE;
        MAKE_DADOS(x,DOUBLE,var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 1)){
        double var = x.dados.DOUBLE + y.dados.LONG;
        MAKE_DADOS(x,DOUBLE,var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2)){
        double var = x.dados.DOUBLE + y.dados.DOUBLE;
        MAKE_DADOS(x,DOUBLE,var);
    }
    push(s,x);
}

void sub (STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1)) {
         long var = y.dados.LONG - x.dados.LONG;
         MAKE_DADOS(x,LONG,var);
    }
    else if ((descobreTipo(y) == 1) && (descobreTipo(x) == 2)) {
        double var = y.dados.LONG - x.dados.DOUBLE;
        MAKE_DADOS(x,DOUBLE,var);
    }
    else if ((descobreTipo(y) == 2) && (descobreTipo(x) == 1)){
        double var = y.dados.DOUBLE - x.dados.LONG;
        MAKE_DADOS(x,DOUBLE,var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2)){
        double var = y.dados.DOUBLE - x.dados.DOUBLE;
        MAKE_DADOS(x,DOUBLE,var);
    }
    push(s,x);
}

void mult (STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1)) {
         long var = x.dados.LONG * y.dados.LONG;
         MAKE_DADOS(x,LONG,var);
    }
    else if ((descobreTipo(x) == 1) && (descobreTipo(y) == 2)) {
        double var = x.dados.LONG * y.dados.DOUBLE;
        MAKE_DADOS(x,DOUBLE,var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 1)){
        double var = x.dados.DOUBLE * y.dados.LONG;
        MAKE_DADOS(x,DOUBLE,var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2)){
        double var = x.dados.DOUBLE * y.dados.DOUBLE;
        MAKE_DADOS(x,DOUBLE,var);
    }
    push(s,x);
}

void quoc (STACK *s){
    //convertDouble(s);
    DATA x = pop(s);
    DATA y = pop(s);
    if ((descobreTipo(x) == 1) && (descobreTipo(y) == 1)) {
        long var = (y.dados.LONG) / (x.dados.LONG);
        MAKE_DADOS(x,LONG,var);
    }
    else if ((descobreTipo(y) == 1) && (descobreTipo(x) == 2)) {
        double var = y.dados.LONG / x.dados.DOUBLE;
        MAKE_DADOS(x,DOUBLE,var);
    }
    else if ((descobreTipo(y) == 2) && (descobreTipo(x) == 1)){
        double var = y.dados.DOUBLE / x.dados.LONG ;
        MAKE_DADOS(x,DOUBLE,var);
    }
    else if ((descobreTipo(x) == 2) && (descobreTipo(y) == 2)){
        double var = y.dados.DOUBLE / x.dados.DOUBLE;
        MAKE_DADOS(x,DOUBLE,var);
    }
    push(s,x);
}

void dec (STACK *s){
    DATA x = pop(s);
    if (descobreTipo(x) == 1)  {
         long var = x.dados.LONG - 1;
         MAKE_DADOS(x,LONG,var);
    }
    else if (descobreTipo(x) == 2)  {
        double var = x.dados.DOUBLE - 1;
        MAKE_DADOS(x,DOUBLE,var);
    }
    push(s,x);
}

void inc (STACK *s){
    DATA x = pop(s);
    if (descobreTipo(x) == 1)  {
         long var = x.dados.LONG + 1;
         MAKE_DADOS(x,LONG,var);
    }
    else if (descobreTipo(x) == 2)  {
        double var = x.dados.DOUBLE + 1;
        MAKE_DADOS(x,DOUBLE,var);
    }
    push(s,x);
}

void resto (STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    long var = y.dados.LONG % x.dados.LONG;
    MAKE_DADOS(x,LONG,var);
    push(s,x);
}

void expo (STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
   /* if ((descobreTipo(x)==2) && (x.dados.DOUBLE == 0.5)) {
        double var = sqrt(y.dados.LONG);
        MAKE_DADOS(x,DOUBLE,var);
        push(s,x);
    }*/
        long a,b=1;
        for (a=0;a<(x.dados.LONG);a++){
            b=b*(y.dados.LONG);
        }
        MAKE_DADOS(x,LONG,b);
        push(s,x);  
}

void E (STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    long var = y.dados.LONG & x.dados.LONG;
    MAKE_DADOS(x,LONG,var);
    push(s,x);
}

void ou (STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    long var = y.dados.LONG | x.dados.LONG;
    MAKE_DADOS(x,LONG,var);
    push(s,x);
}

void xor (STACK *s){
    DATA x = pop(s);
    DATA y = pop(s);
    long var = y.dados.LONG ^ x.dados.LONG;
    MAKE_DADOS(x,LONG,var);
    push(s,x);
}

void not (STACK *s){
    DATA x = pop(s);
    long var = ~(x.dados.LONG);
    MAKE_DADOS(x,LONG,var);
    push(s,x);
}

void convertInt (STACK *s){
        DATA x = pop(s);
        if (descobreTipo(x) == 1) {
            long var = x.dados.LONG;
            MAKE_DADOS(x,LONG,var);
            }
        else if (descobreTipo(x) == 2) {
            long var = x.dados.DOUBLE;
            MAKE_DADOS(x,LONG,var);
            }
        else if (descobreTipo(x) == 3) {
            long var = x.dados.CHAR;
            MAKE_DADOS(x,LONG,var);
            }
        /*
        else if (descobreTipo(x) == 4) {
            long var = x.dados.STRING;
            MAKE_DADOS(x,LONG,var)
            }
        */
        push(s,x);
}

void convertDouble (STACK *s){
        DATA x = pop(s);
        if (descobreTipo(x) == 1) {
            double var = x.dados.LONG;
            MAKE_DADOS(x,DOUBLE,var);
            }
        else if (descobreTipo(x) == 2) {
            double var = x.dados.DOUBLE;
            MAKE_DADOS(x,DOUBLE,var);
            }
        else if (descobreTipo(x) == 3) {
            double var = x.dados.CHAR;
            MAKE_DADOS(x,DOUBLE,var);
            }
        /*
        else if (descobreTipo(x) == 4) {
            double var = x.dados.STRING;
            MAKE_DADOS(x,DOUBLE,var)
            }
        */
        push(s,x);
}

void convertChar (STACK *s){
        DATA x = pop(s);
        if (descobreTipo(x) == 1) {
            char var = x.dados.LONG;
            MAKE_DADOS(x,CHAR,var);
            }
        else if (descobreTipo(x) == 2) {
            char var = x.dados.DOUBLE;
            MAKE_DADOS(x,CHAR,var);
            }
        else if (descobreTipo(x) == 3) {
            char var = x.dados.CHAR;
            MAKE_DADOS(x,CHAR,var);
            }
        /*
        else if (descobreTipo(x) == 4) {
            char var = x.dados.STRING;
            MAKE_DADOS(x,CHAR,var)
            }
        */
        push(s,x);
}

/*
void convertString (STACK *s){
    
}
*/