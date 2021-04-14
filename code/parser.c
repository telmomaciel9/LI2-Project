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
#include "operations.h"


/** 
 * \brief Esta é a função que vai fazer o parse de uma linha.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @returns A stack final depois de ser feito o parse.
 */

#define MAKE_DADOS(var, TYPE, valor)                 \
        var.dados.TYPE = valor;                      \
        var.type = TYPE;

int descobreTipo (DATA x){
    if (x.type == LONG) return 1;  
    else if (x.type == DOUBLE) return 2;
    else if (x.type == CHAR) return 3;
    else if (x.type == STRING) return 4;
    
    return 0;
}

void parse (char * line, STACK* s){
    char *token;
    char *delims = " \t\n";
    float a;
    long b;
    char *sobra;
    char *sobraint;
    char aux2[10000];
    char aux[10000];
    passData(line,aux);
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
        else if (strcmp (token, "l") == 0){

            assert( fgets (aux2 ,10000,stdin) != NULL);

            assert ( aux2 [strlen (aux2) - 1] == '\n'   );

            parse2 (aux2,s);
            parse (strstr(aux, token) + strlen (token),s);
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
            duplica(s);
        }
        else if (strcmp (token, ";") == 0){
             pop(s);
        }
        else if (strcmp (token, "\\") == 0){
            swap(s);
        }
        else if (strcmp (token, "@") == 0){
            rotate(s);
        }
        else if (strcmp (token, "$") == 0){
            copy(s);
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
        else if (strlen(token)==1) {

            MAKE_DADOS(vall,CHAR,*token);
            push(s,vall);
        }
        else if (strlen(token)>1){  

            MAKE_DADOS(vall,STRING,strdup(token));
            push(s,vall);
        }
        /*
        else if (strcmp (token, "s") == 0) {

            DATA x = pop(s);
            char * var = x.dados.STRING;
            MAKE_DADOS(x,STRING,var);
            push(s,x);
            
        }
        */
    }    
}     

void passData (char* v, char* s){
    int i;
    for(i=0 ;v[i] != '\0' ; i++){
       s[i] = v[i];
    }
    s[i] = '\0';
}

void parse2 (char* line, STACK* s){
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
        else if (strlen(token)==1) {

            MAKE_DADOS(vall,CHAR,*token);
            push(s,vall);
        }
        else if (strlen(token)>1){  

            MAKE_DADOS(vall,STRING,strdup(token));
            push(s,vall);
        }
}
}
