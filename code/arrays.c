/**
 * @file arrays.c
 *
 *  Ficheiro que contem as funções que dizem respeito à arrays.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"
#include "stack.h"
//#include "operations.h"
//#include "logica.h"
#include "arrays.h"

/*! 
  \brief Esta macro converte o valor para o tipo que desejamos
  \param var Variável onde vai ficar armazenado o valor convertido.
  \param TYPE Tipo para o qual vai ser convertido o valor.
  \param valor Variável onde está guardado o valor a converter.
 */

#define MAKE_DADOS(var, TYPE, valor) \
    var.dados.TYPE = valor;          \
    var.type = TYPE;

/** 
 * \brief Esta é a função que cria e inicializa uma stack.
 * 
 * @param s é apontador para a stack.
 *
 */
void criaArray(STACK *s)
{
    DATA x = pop(s);
    if (x.type == ARRAY)
    {
        int cont;
        cont = x.dados.ARRAY->n_elems;
        //printf("%d\n", x.dados.ARRAY -> n_elems);
        MAKE_DADOS(x, LONG, cont);
        push(s, x);
    }
    if (x.type == STRING)
    {
        int i, cont = 0;
        for (i = 0; x.dados.STRING[i] != '\0'; i++)
        {
            cont++;
        }
        MAKE_DADOS(x, LONG, cont)
        push(s, x);
    }
    else
    {
        DATA y;
        STACK *a = create_stack();
        int i;
        for (i = 0; i < x.dados.LONG; i++)
        {
            MAKE_DADOS(y, LONG, i);
            push(a, y);
            //printf("%ld\n", y.dados.LONG);
        }
        MAKE_DADOS(y, ARRAY, a);
        push(s, y);
    }
}

/** 
 * \brief Esta é a função que ...
 * 
 * @param s é apontador para a stack.
 *
 * @param line ...
 *
 * @param rest ...
 *
 * @param v variável ...
 *
 */

void parseArray(STACK *s, char *line, char **rest, VAR *v)
{
    STACK *s_array = create_stack();
    char *seps = "[]";
    line = get_delimited(line, seps, rest);
    //printf(" ");
    parse(line, s_array, v);
    DATA t;
    MAKE_DADOS(t, ARRAY, s_array);
    push(s, t);
}

/** 
 * \brief Esta é a função que ...
 * 
 * @param s é apontador para a stack.
 *
 */
void whitespace(STACK *s)
{
    DATA x = pop(s);
    STACK *s_array = create_stack();
    DATA t;
    int i = 0;
    if (x.type == STRING)
    {

        char *aux;
        aux = (char *)malloc(100 * sizeof(char *));

        while (*x.dados.STRING != '\0')
        {
            while ((*x.dados.STRING == ' ' || *x.dados.STRING == '\t' || *x.dados.STRING == '\n') && *x.dados.STRING != '\0')
            {
                x.dados.STRING++;
            }

            while ((*x.dados.STRING != ' ' || *x.dados.STRING != '\t' || *x.dados.STRING != '\n') && *x.dados.STRING != '\0')
            {

                aux[i] = *x.dados.STRING;
                x.dados.STRING++;
                i++;
            }
            aux[i] = '\0';

            MAKE_DADOS(t, STRING, aux);
            push(s_array, t);
        }

        MAKE_DADOS(x, ARRAY, s_array);
        push(s, x);
    }
}

/*void newlines (STACK *s){

}*/
