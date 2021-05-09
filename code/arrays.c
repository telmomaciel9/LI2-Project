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
    else if (x.type == STRING)
    {
        MAKE_DADOS(x, LONG, strlen(x.dados.STRING));
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
        DATA x;
        MAKE_DADOS(x, ARRAY, a);
        push(s, x);
    }
}

/** 
 * \brief Esta é a função que faz parse dos elementos da array.
 * 
 * @param s é apontador para a stack.
 *
 * @param line apontador para uma string, que armazena os tokens.
 *
 * @param rest apontador para onde se guardam as restantes strings.
 *
 * @param v apontador para um tipo var.
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
 * \brief Esta é a função que verifica os casos especiais de mudança de linha e espaço em branco.
 * 
 * @param s é apontador para a stack.
 *
 * @param token apontador para o elemento em causa, que está a ser tratado.
 */
void whiteNewSpace(STACK *s, char *token)
{
    if (strcmp(token, "S/") == 0)
    {
        DATA x = pop(s);
        DATA t;
        STACK *s_array = create_stack();
        if (x.type == STRING)
        {
            while (*x.dados.STRING != '\0')
            {
                int j = 0;
                char *aux = (char *)malloc(strlen(x.dados.STRING) * sizeof(char *));
                while ((*x.dados.STRING == ' ' || *x.dados.STRING == '\t' || *x.dados.STRING == '\n') && *x.dados.STRING != '\0')
                {
                    x.dados.STRING++;
                }
                while (*x.dados.STRING != ' ' && *x.dados.STRING != '\t' && *x.dados.STRING != '\n' && *x.dados.STRING != '\0')
                {
                    aux[j] = *x.dados.STRING;
                    j++;
                    x.dados.STRING++;
                }

                //printf("%s\n",aux);
                aux[j] = '\0';
                MAKE_DADOS(t, STRING, aux);
                push(s_array, t);
            }
            pop(s_array);
            MAKE_DADOS(x, ARRAY, s_array);
            push(s, x);
        }
    }
    else if (strcmp(token, "N/") == 0)
    {
        DATA x = pop(s);
        DATA t;
        STACK *s_array = create_stack();
        if (x.type == STRING)
        {
            while (*x.dados.STRING != '\0')
            {
                int j = 0;
                char *aux = (char *)malloc(strlen(x.dados.STRING) * sizeof(char *));
                while (*x.dados.STRING == '\n' && *x.dados.STRING != '\0')
                {
                    x.dados.STRING++;
                }
                while (*x.dados.STRING != '\n' && *x.dados.STRING != '\0')
                {
                    aux[j] = *x.dados.STRING;
                    j++;
                    x.dados.STRING++;
                }

                //printf("%s\n",aux);
                aux[j] = '\0';
                MAKE_DADOS(t, STRING, aux);
                push(s_array, t);
            }
            pop(s_array);
            MAKE_DADOS(x, ARRAY, s_array);
            push(s, x);
        }
    }
}

/*void newlines (STACK *s){
    DATA x = pop(s);
    DATA t;
    STACK *s_array = create_stack();
    if (x.type == STRING)
    {
        while (*x.dados.STRING != '\0')
        {
             int j=0;
             char* aux = (char *) malloc (strlen(x.dados.STRING) * sizeof(char *) );
             while (*x.dados.STRING == '\n' && *x.dados.STRING != '\0') 
             {
             x.dados.STRING++;
             }
             while (*x.dados.STRING != '\n' && *x.dados.STRING != '\0')
             {  
                 aux[j] = *x.dados.STRING;
                 j++;
                 x.dados.STRING++;
             }

            //printf("%s\n",aux);
            aux[j] = '\0';
            MAKE_DADOS(t, STRING, aux);
            push(s_array, t);
        }
        pop(s_array);
        MAKE_DADOS(x, ARRAY, s_array);
        push(s, x);
    }
}*/
