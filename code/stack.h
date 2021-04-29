/**
 * @file stack.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro stack.h.
 */

#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>

/// Isto é um enum para distinguir tipos
typedef enum {

    LONG = 1,   ///< TIPO LONG
    DOUBLE = 2, ///< TIPO DOUBLE
    CHAR = 4,   ///< TIPO CHAR
    STRING = 8,  ///< TIPO STRING
    ARRAY = 16

} TYPE;       /** < nome atribuído ao tipo do enum */

/**@def INTEGER
      Define INTEGER como LONG ou CHAR
 */
#define INTEGER (LONG | CHAR)

/**@def NUMBER
      Define NUMBER como INTEGER ou DOUBLE
 */
#define NUMBER (INTEGER | DOUBLE)

/** @struct DATA
 *  data
 *  
 *  @brief Esta struct serve para distinguir os tipos de váriaveis da stack.
 *  @var data::type
 *      Distingue os tipos dos elementos da stack.
 *  @var data::union
 *  ///\union
 *        @var union::LONG
 *        @var union::DOUBLE
 *        @var union::CHAR
 *        @var union::STRING
 */

typedef struct data {
    TYPE type;
    /**
     * \union dados
     * Armazena uma variável dependedo do seu tipo
     */
  union {

        long LONG;     /** < LONG armazena o valor de uma variável do tipo Long */
        double DOUBLE; /** < DOUBLE armazena o valor de uma variável do tipo Double */
        char CHAR;     /** < CHAR armazena o valor de uma variável do tipo Char */
        char *STRING;  /** < STRING armazena o valor de uma variável do tipo String */
        struct stack *ARRAY;

    } dados;         /** < nome atribuído ao tipo do union */

} DATA;            /** < nome atribuído ao tipo da struct data */

/** @struct STACK 
 *  Stack
 * 
 * 
 *  @brief Esta struct define os tipos contidos na stack.
 *  @var stack::size
 *  @var stack::n_elems
 */

typedef struct stack {

    DATA *stack; /** < apontador para variáveis do tipo DATA*/
    int size;    /** < size armazena o valor de uma variável do tipo Int que se refere ao tamanho da stack*/
    int n_elems; /** < n_elems refere-se ao número de elementos da stack*/

} STACK;       /** < nome atribuído ao tipo da struct stack */


STACK *create_stack();

void push(STACK *s, DATA elem);

DATA pop(STACK *s);

DATA top(STACK *s);

DATA obterElemento(STACK *s, long x);

int is_empty(STACK *s);

void print_stack(STACK *s);

#endif