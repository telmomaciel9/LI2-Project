#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "stack.h"
#include "blocos.h"
//#include "parser.h"

/** 
 * \brief Função que executa o que está dentro do bloco.
 * 
 * @param s apontador para a stack.
 * 
 * @param v apontador para uma variável.
 *
 */
/*
void executaBloco (STACK* s , VAR* v) {
    DATA x = pop(s);
    DATA y = pop(s);
    if (x.type == BLOCO){
    x.dados.BLOCO++;
    char* aux1 = (char *) malloc(sizeof(char) * strlen(x.dados.BLOCO));
    STACK* aux = create_stack();
    int a = strlen(x.dados.BLOCO);

    strcpy(aux1,x.dados.BLOCO);
    aux1[a-2] = '\0';

    push(aux,y);
    
    parse(aux1,aux,v);
    
    //print_stack(aux);

    MAKE_DADOS(x,ARRAY,aux);
    push(s,x);
}
}*/

/** 
 * \brief Função que faz o map.
 * 
 * @param s apontador para a stack.
 * 
 * @param v apontador para uma variável.
 *
 */
/*
void aplicaArrays (STACK* s, VAR* v) {
    DATA x = pop(s); // x é bloco
    DATA y = pop(s); // y é array
    int i;
    if (x.type == BLOCO && y.type == ARRAY) {
        x.dados.BLOCO++;
        char* aux1 = (char *) malloc(sizeof(char) * strlen(x.dados.BLOCO));
        STACK* aux = create_stack();
        strcpy(aux1,x.dados.BLOCO);
        int a = strlen(x.dados.BLOCO);
        aux1[a-2] = '\0';
        int b = y.dados.ARRAY->n_elems;
        y.dados.ARRAY -> n_elems = 1;
        for(i=0; i<b; i++) {
            DATA t = top(y.dados.ARRAY);
            push(aux,t);
            //print_stack(aux);
           // printf("\n");
            //printf("%s",x.dados.BLOCO);
            parse(aux1,aux,v);
            y.dados.ARRAY->n_elems++;
        } 
        MAKE_DADOS(x,ARRAY,aux);
        push(s,x);
    }
    else if (x.type == BLOCO && y.type == STRING){
        x.dados.BLOCO++;
        int a = strlen(x.dados.BLOCO);
        char* aux1 = (char *) malloc(sizeof(char) * strlen(x.dados.BLOCO));
        //char* aux2 = (char *) malloc(sizeof(char) * strlen(y.dados.STRING));
        strcpy(aux1,x.dados.BLOCO);
        aux1[a-2] = '\0';
        int c = strlen(y.dados.STRING);
        for (i=0; i<c; i++){
        DATA t;
        STACK* s1 = create_stack();
        MAKE_DADOS(t,CHAR,y.dados.STRING[i]);
        push(s1,t);
        parse(aux1,s1,v);
        if (top(s1).type == CHAR){
           y.dados.STRING[i] = top(s1).dados.LONG;
           //printf("%c",y.dados.STRING[i]);
        }
        }
        y.dados.STRING[i] = '\0';
        MAKE_DADOS(x,STRING,y.dados.STRING);
        push(s,x);
    }
 }
*/
/**
 * \brief Função que dada um bloco, faz uma filter da stack.
 * 
 * @param s apontador para a stack.
 *
 * @param v apontador para VAR.
 */
/*
void filter (STACK* s, VAR* v){
     DATA x = pop(s);
     DATA y = pop(s);
     int i;
    if (x.type == BLOCO && y.type == ARRAY) {
        x.dados.BLOCO++;
        STACK* aux = create_stack();
        STACK* aux2 = create_stack();
        char* aux1 = (char *) malloc(sizeof(char) * strlen(x.dados.BLOCO));
        strcpy(aux1,x.dados.BLOCO);
        int a = strlen(x.dados.BLOCO);
        aux1[a-2] = '\0';
        int b = y.dados.ARRAY->n_elems;
        y.dados.ARRAY -> n_elems = 1;
        for(i=0; i<b; i++){
            DATA t = top(y.dados.ARRAY);
            push(aux,t);
            parse(aux1,aux,v);
            if (aux->stack[i].dados.LONG == 1) {
               push(aux2,t);
               //printf("%ld\n",aux->stack[d].dados.LONG);
            }
            y.dados.ARRAY->n_elems++;
        } 
        MAKE_DADOS(x,ARRAY,aux2);
        push(s,x);
    }
   if (x.type == BLOCO && y.type == STRING){
        x.dados.BLOCO++;
        int a = strlen(x.dados.BLOCO);
        char* aux1 = (char *) malloc(sizeof(char) * strlen(x.dados.BLOCO));
        strcpy(aux1,x.dados.BLOCO);
        aux1[a-2] = '\0';
        int k=0;
        int c = strlen(y.dados.STRING);
        //printf("%d",c);
        for (i=0; i<c; i++){
        STACK* s1 = create_stack();
        DATA t;
        MAKE_DADOS(t,CHAR,y.dados.STRING[i]);
        //printf ("%c\n",y.dados.STRING[i]);
        push(s1,t);
        parse(aux1,s1,v);
        if (top(s1).dados.LONG) {
            y.dados.STRING[k] = y.dados.STRING[i];
            k++;
        }
        }
        y.dados.STRING[k] = '\0';
        push(s,y);
        }  
    }
*/
/*
void fold (STACK *s, VAR* v){
     DATA x = pop(s);
     DATA y = pop(s);
    if (x.type == BLOCO && y.type == ARRAY){
        x.dados.BLOCO++;
        int i;
        int a = strlen(x.dados.BLOCO);
        char* aux1 = (char *) malloc(sizeof(char) * strlen(x.dados.BLOCO));
        STACK* aux = create_stack();
        strcpy(aux1,x.dados.BLOCO);
        aux1[a-2] = '\0';
        int tam = y.dados.ARRAY->n_elems;
        push(aux,y.dados.ARRAY->stack[0]);
        for(i=0;i<tam;i++){
           push(aux,y.dados.ARRAY->stack[i]);
           parse(aux1,aux,v);
        }
        y.dados.ARRAY = aux;
        push(s,y);
     }
}
*/
/*void executaBlocoTruthy (STACK *s, VAR *v){
    DATA x = top(s);
    //DATA y = pop(s);
    if (x.type == BLOCO){
    executaBloco(s,v);
    while (pop(s).dados.LONG){
           push(s,x);
           executaBloco(s,v);
    }
  }      
}*/