/**
 * @file stack.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro stack.h.
 */

#ifndef ___STACK_H___
#define ___STACK_H___

#include <assert.h>

/// Isto é um enum para distinguir tipos
typedef enum
{
  LONG = 1, ///< TIPO LONG
  DOUBLE = 2, ///< TIPO DOUBLE
  CHAR = 4, ///< TIPO CHAR
  STRING = 8 ///< TIPO STRING
} TYPE;

/**@def INTEGER
      Define INTEGER como LONG ou CHAR
 */
#define INTEGER (LONG | CHAR)

/**@def NUMBER
      Define NUMBER como INTEGER ou DOUBLE
 */
#define NUMBER (INTEGER | DOUBLE)

/** @struct data
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
typedef struct data
{
  TYPE type;
  union
  {
    long LONG;
    double DOUBLE;
    char CHAR;
    char *STRING;
  } dados;
} DATA;

/** @struct stack
 *  @brief Esta struct define os tipos contidos na stack.
 *  @var stack::size
 *  @var stack::n_elems
 */
typedef struct stack
{
  DATA *stack;
  int size;
  int n_elems;
} STACK;

int descobreTipo(DATA x);
int has_type(DATA elem, int mask);
STACK *create_stack();
void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
DATA obterElemento(STACK *s, long x);
int is_empty(STACK *s);
void print_stack(STACK *s);

//////////////////////////////////////////////////

#define STACK_OPERATION_PROTO(_type, _name) \
  void push_##_name(STACK *s, _type val);   \
  _type pop_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)

#endif