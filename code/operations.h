/**
 * @file operations.h 
 * 
 * Ficheiro que contém as declarações das funções do ficheiro operations.c
 */

#include "stack.h"
//#include "parser.h"

void ifcond(STACK *s);

/** 
 * \brief Esta é a função que vai fazer a soma de dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void soma(STACK *s);

/** 
 * \brief Esta é a função, auxiliar, que vai fazer a soma de dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxSoma4(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função, auxiliar, que vai fazer a soma de dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxSoma3(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função, auxiliar, que vai fazer a soma de dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxSoma2(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função, auxiliar, que vai fazer a soma de dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxSoma(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função,auxiliar, que multiplica dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxMult(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função, auxiliar, que multiplica dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxMult2(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função, auxiliar, que multiplica dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxMult3(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função, auxiliar, que divide dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxQuoc(STACK *s, DATA x, DATA y);

/** 
 * \brief Esta é a função, auxiliar, que divide dois valores.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param x elemento que faz pop.
 * 
 * @param y elementos que faz pop.
 */

void auxQuoc2(STACK *s, DATA x, DATA y);

void auxExpo(STACK *s,DATA x, DATA y);

void auxExpo2(STACK *s,DATA x, DATA y);

void sub(STACK *s);

/** 
 * \brief Esta é a função que multiplica dois valores.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void mult(STACK *s);

/** 
 * \brief Esta é a função que divide dois valores um pelo outro.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void quoc(STACK *s);

/** 
 * \brief Função que realiza operações do 'e' lógico (bitwise) para inteiros.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void E(STACK *s);

/**
* \brief Função que realiza operações not (bitwise) para inteiros.
*
*
* @param s Stack onde vão ser armazenados os valores.
*
*/

void not(STACK * s);

/** 
 * \brief Função que realiza operações xor (bitwise) para inteiros.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void xor (STACK * s);

/** 
 * \brief Função que realiza operações do 'ou' lógico (bitwise) para inteiros.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void ou(STACK *s);

/** 
 * \brief Esta é a função é responsável por decrementar 1 valor.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void dec(STACK *s);

/** 
 * \brief Esta é a função responsável por incrementar 1 valor.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void inc(STACK *s);

/** 
 * \brief Esta é a função que vai apresentar o resto da divisão.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void resto(STACK *s);

/** 
 * \brief Esta é a função responsável pela exponencialização de valores.
 * 
 *
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void expo(STACK *s);

/** 
 * \brief Função que executa o que está dentro do bloco.
 * 
 * @param s apontador para a stack.
 * 
 * @param v apontador para uma variável.
 *
 */

void executaBloco(STACK *s, VAR *v);

/** 
 * \brief Função que converte o valor do topo da stack para inteiro.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void convertInt(STACK *s);

/** 
 * \brief Função que converte o valor do topo da stack para caractere.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void convertChar(STACK *s);

/** 
 * \brief Função que converte o valor do topo da stack para double.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void convertDouble(STACK *s);

//void convertString (STACK *s);

/** 
 * \brief Função que troca os últimos 2 elementos da stack.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void swap(STACK *s);

/** 
 * \brief Função que roda os últimos 3 elementos da stack.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void rotate(STACK *s);

/** 
 * \brief Função que copia o n-ésimo elemento para o topo da stack.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void copy(STACK *s);

/** 
 * \brief Função que duplica o último elemento da stack.
 *
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 */

void duplica(STACK *s);

/**
 * \brief Função que decide a operação a ser feita consoante o tipo do elemento
 * 
 * @param token Elemento pertencente à stack que vai ser tratado.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 * 
 * @param v apontador para uma variável.
 */

void handle_ahritmetic(char *token, STACK *s, VAR *v);

/** 
 * \brief Esta é a função que aplica uma operação a uma stack.
 * 
 * @param s Stack onde vão ser armazenados os valores.
 *
 * @param v apontador para uma variável.
 */

void fold(STACK *s, VAR *v);

/** 
 * \brief Função que faz o map.
 * 
 * @param s apontador para a stack.
 * 
 * @param v apontador para uma variável.
 *
 */

void aplicaArrays(STACK *s, VAR *v);

/**
 * \brief Função que dada um bloco, faz uma filter da stack.
 * 
 * @param s apontador para a stack.
 *
 * @param v apontador para VAR.
 */

void filter(STACK *s, VAR *v);