/**
 * @file stack.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro stack.h.
 */

#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>

//#include "variables.h"

/// Isto é um enum para distinguir tipos
typedef enum
{

    LONG = 1,   ///< TIPO LONG
    DOUBLE = 2, ///< TIPO DOUBLE
    CHAR = 4,   ///< TIPO CHAR
    STRING = 8, ///< TIPO STRING
    ARRAY = 16, ///< TIPO ARRAY
    BLOCO = 32 ///< TIPO BLOCO

} TYPE; /** < nome atribuído ao tipo do enum */

/**@def INTEGER
      Define INTEGER como LONG ou CHAR
 */
#define INTEGER (LONG | CHAR)

/**@def NUMBER
      Define NUMBER como INTEGER ou DOUBLE
 */
#define NUMBER (INTEGER | DOUBLE)


/** @struct data
 * 
 *  @brief Esta struct serve para establecer os tipos dos elementos.
 * 
 */


typedef struct data
{
    TYPE type; /** < O parâmetro type é referente ao tipo que a variável vai ter. */
               /**
     * \union dados
     * Armazena uma variável dependedo do seu tipo
     */
    union
    {
        long LONG;     /** < LONG armazena o valor de uma variável do tipo Long */
        double DOUBLE; /** < DOUBLE armazena o valor de uma variável do tipo Double */
        char CHAR;     /** < CHAR armazena o valor de uma variável do tipo Char */
        char *STRING;  /** < STRING armazena o valor de uma variável do tipo String */
        struct stack *ARRAY;  /** < ARRAY armazena o valor de uma variável do tipo Struct Stack **/
        char *BLOCO;  /** < BLOCO armazena o valor de uma variável do tipo String */



    } dados; /** < nome atribuído ao tipo do union */

} DATA; /** < nome atribuído ao tipo da struct data */

/** @struct STACK 
 *  Stack
 * 
 * 
 *  @brief Esta struct define os tipos contidos na stack.
 *  @var stack::size
 *  @var stack::n_elems
 */

typedef struct stack
{
    DATA *stack; /** < apontador para variáveis do tipo DATA*/
    int size;    /** < size armazena o valor de uma variável do tipo Int que se refere ao tamanho da stack*/
    int n_elems; /** < n_elems refere-se ao número de elementos da stack*/

} STACK; /** < nome atribuído ao tipo da struct stack */

/** 
 * \brief Esta é a função que vai criar a stack.
 *
 * @returns s
 */

STACK *create_stack();

/** 
 * \brief Esta é a função que vai fazer o push de um elemento na stack.
 * 
 * @param s é apontador para a stack.
 * 
 * @param elem é o elemento que vai ser adicionado no topo da stack.
 *
 */

void push(STACK *s, DATA elem);

/** 
 * \brief Esta é a função que vai fazer o pop numa stack.
 * 
 * @param s é apontador para a stack.
 *
 * @returns s->stack[s->n_elems]
 */

DATA pop(STACK *s);

/** 
 * \brief Esta é a função que verifica o elemento que está no topo da stack.
 * 
 * @param s é apontador para a stack.
 * 
 * @returns s->stack[s->n_elems - 1]
 *
 */

DATA top(STACK *s);

/** 
 * \brief Esta é a função que verifica o elemento que está na base da stack.
 * 
 * @param s é apontador para a stack.
 * 
 * @returns s->stack[s->n_elems - s->n_elems]
 *
 */

DATA bottom(STACK *s);

/** 
 * \brief Esta é a função que vai buscar a posição da stack, de um certo elemento.
 * 
 * @param s é apontador para a stack.
 * 
 * @param x, do tipo long, que é o elemento cuja posição estamos à procura.
 *
 * @returns y
 */

DATA obterElemento(STACK *s, long x);

/** 
 * \brief Esta é a função que verifica se a stack está vazia.
 * 
 * @param s é apontador para a stack.
 * 
 * @returns 1 se a condição for verdadeira ou 0 se for falso.
 *
 */

int is_empty(STACK *s);

/** 
 * \brief Esta é a função que imprime a stack no ecrã.
 * 
 * @param s é apontador para a stack.
 *
 */

void print_stack(STACK *s);

#endif