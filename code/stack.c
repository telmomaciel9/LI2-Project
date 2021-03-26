/**
 * @file stack.c Funções que dizem respeito à stack.
 */ 

#include <stdio.h>
#include "stack.h"

 
/** @param stack Stack onde se vai guardar os valores.
 */     
int stack[10000];
/** @param top Tamanho atual da stack.
 */     
int top = -1;            

/**
 * \brief Esta é função que vai retirar o último elemento da stack.
 * 
 * @returns O elemento que está por cima da stack.
 */

int pop() {
   int data;
      data = stack[top];
      top = top - 1;   
      return data;

}

/**
 * \brief Esta é a função que vai adicionar um elemento na stack.
 * 
 * @param data Valor que vai ser adicionado à stack.
 * 
 * @returns O valor 0.
 */ 

int push(int data) {
      top = top + 1;   
      stack[top] = data;
      return 0;
}

/**
 * \brief Esta é a função que vai dar print da stack final.
 * 
 * @returns O valor 0.
 */

int printstack (){
    int i; 
    for (i=0;i<=top;i++){
        printf("%d", stack[i]);
    } 
    return 0;
}