/**
 * @file stack.c 
 *
 * Funções que dizem respeito à manipulação da stack.
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
/*
int has_type(DATA elem, int mask)
{
  return (elem.type & mask) != 0;
}
*/

/** 
 * \brief Esta é a função que vai criar a stack.
 *
 * @returns s
 */

STACK *create_stack()
{
    STACK *s = (STACK *)calloc(1, sizeof(STACK));
    //s->n_elems = 0;
    s->size = 100;
    s->stack = (DATA *)calloc(s->size, sizeof(DATA));
    return s;
}

/** 
 * \brief Esta é a função que vai fazer o push de um elemento na stack.
 * 
 * @param s é apontador para a stack.
 * 
 * @param elem é o elemento que vai ser adicionado no topo da stack.
 *
 */

void push(STACK *s, DATA elem)
{
    if (s->size == s->n_elems)
    {
        s->size += 100;
        s->stack = (DATA *)realloc(s->stack, s->size * sizeof(DATA));
    }
    s->stack[s->n_elems] = elem;
    s->n_elems++;
}

/** 
 * \brief Esta é a função que vai fazer o pop numa stack.
 * 
 * @param s é apontador para a stack.
 *
 * @returns s->stack[s->n_elems]
 */

DATA pop(STACK *s)
{
    s->n_elems--;
    return s->stack[s->n_elems];
}

/** 
 * \brief Esta é a função que verifica o elemento que está no topo da stack.
 * 
 * @param s é apontador para a stack.
 * 
 * @returns s->stack[s->n_elems - 1]
 *
 */

DATA top(STACK *s)
{
    return s->stack[s->n_elems - 1];
}

/** 
 * \brief Esta é a função que verifica o elemento que está na base da stack.
 * 
 * @param s é apontador para a stack.
 * 
 * @returns s->stack[s->n_elems - s->n_elems]
 *
 */

DATA bottom(STACK *s)
{
    return s->stack[s->n_elems - s->n_elems];
}

/** 
 * \brief Esta é a função que vai buscar a posição da stack, de um certo elemento.
 * 
 * @param s é apontador para a stack.
 * 
 * @param x, do tipo long, que é o elemento cuja posição estamos à procura.
 *
 * @returns y
 */

DATA obterElemento(STACK *s, long x)
{
    DATA y = s->stack[s->n_elems - x - 1];
    //s->n_elems+x+1;
    return y;
}

/** 
 * \brief Esta é a função que verifica se a stack está vazia.
 * 
 * @param s é apontador para a stack.
 * 
 * @returns 1 se a condição for verdadeira ou 0 se for falso.
 *
 */

int is_empty(STACK *s)
{
    return s->n_elems == 0;
}

/** 
 * \brief Esta é a função que imprime a stack no ecrã.
 * 
 * @param s é apontador para a stack.
 *
 */

void print_stack(STACK *s)
{
    for (int K = 0; K < s->n_elems; K++)
    {
        DATA elem = s->stack[K];
        TYPE type = elem.type;
        switch (type)
        {
        case LONG:
            printf("%ld", elem.dados.LONG);
            break;
        case DOUBLE:
            printf("%g", elem.dados.DOUBLE);
            break;
        case CHAR:
            printf("%c", elem.dados.CHAR);
            break;
        case STRING:
            printf("%s", elem.dados.STRING);
            break;
        case ARRAY:
            print_stack(elem.dados.ARRAY);
            break;
        case BLOCO:
            printf("%s", elem.dados.BLOCO);
            break;
        }
    }
    //  printf("\n");
}

/*#define STACK_OPERATION(_type, _name)       \
  void push_##_name(STACK *s, _type val) {    \
    DATA elem;                                \
    elem.type = _name;                        \
    elem._name = val;                         \
    push(s, elem);                            \
  }                                           \
  _type pop_##_name(STACK *s) {               \
    DATA elem = pop(s);                       \
    assert(elem.type == _name);               \
    return elem._name;                        \
  }

STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)*/