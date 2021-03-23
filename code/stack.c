/**
 * @file Funções que dizem respeito à stack.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "stack.h"

/**
 * \brief Esta é função que vai retirar o último elemento da stack.
 * 
 * @param stack Stack no momento que se chama a função.
 * @param top Tamanho da stack.
 * 
 * @returns O elemento que está por cima da stack.
 */

int pop (int stack[],int top){
    int item=0;
    if (top!=-1){
        item = stack[top];
        top = top - 1;
    }
    return item;
}

/**
 * \brief Esta é a função que vai adicionar um elemento na stack.
 * 
 * @param stack Stack no momento que é chamada a função.
 * @param top Tamanho da stack.
 * @param MaxStack Tamanho máximo da stack.
 * @param item Elemento que queremos adicionar à stack.
 */ 
void push (int stack[], int top, int MaxStack, int item){
    if (top != MaxStack - 1){
        top = top + 1;
        stack[top] = item;
    }
}
