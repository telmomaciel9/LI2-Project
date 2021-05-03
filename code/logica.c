/**
 * @file logica.c
 *
 *  Ficheiro que contem as funções que dizem respeito à parte lógica.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "parser.h"
#include "stack.h"
#include "logica.h"

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
 * \brief Esta é a função que decide o comportamento a adotar consoante uma condição "se".
 * 
 * @param s é apontador para a stack.
 *
 */

void ifcond(STACK *s)
{
    switch (s->n_elems)
    {
    case (0):
        break;
    case (1):
        break;
    case (2):
    {
        DATA x = pop(s);
        push(s, x);
        break;
    }
    default:
    {
        DATA x = pop(s);
        DATA y = pop(s);
        DATA z = pop(s);
        if (z.dados.LONG == 0)
            push(s, x);
        else
            push(s, y);
        break;
    }
    }
}

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma condição "igual".
 * 
 * @param s é apontador para a stack.
 *
 */

void igual(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    if ((x.type == LONG && y.type == LONG) || (x.type == DOUBLE && y.type == DOUBLE))
    {
        long a = x.dados.LONG == y.dados.LONG;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    } else if (x.type == LONG && y.type == DOUBLE) {
        long a = x.dados.LONG == y.dados.DOUBLE;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    } else if (x.type == DOUBLE && y.type == LONG) {
        long a = x.dados.DOUBLE == y.dados.LONG;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    } else if ((x.type == LONG && y.type == CHAR) || (x.type == CHAR && y.type == LONG) ||
               (x.type == CHAR && y.type == CHAR)) {
        long a = x.dados.DOUBLE == y.dados.DOUBLE;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    } else if (x.type == DOUBLE && y.type == CHAR) {
        long a = x.dados.DOUBLE == y.dados.CHAR;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    } else if (x.type == CHAR && y.type == DOUBLE) {
        long a = x.dados.CHAR == y.dados.DOUBLE;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
     else if (x.type == LONG && y.type == ARRAY){
         STACK* nova = y.dados.ARRAY;
         nova->n_elems= x.dados.LONG + 1;
         x=top(nova);
         push(s, x);
     }
     else if (x.type == LONG && y.type == STRING) {
         char a = *(y.dados.STRING + x.dados.LONG);
         MAKE_DADOS(x,CHAR,a);
         push(s,x);
     }
     else if (x.type == STRING && y.type == STRING) {
        int i = 0;
        while (*x.dados.STRING != '\0' && *y.dados.STRING != '\0') {
            if (*x.dados.STRING == *y.dados.STRING) {
                i = 1;
                break;
            }
            else {
                i = 0;
                break;
            }
            x.dados.STRING++;
            y.dados.STRING++;
        } 
        DATA t;
        MAKE_DADOS(t,LONG,i);
        push(s,t);
    }

}

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma condição "maior".
 * 
 * @param s é apontador para a stack.
 *
 */

void maior(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    if ((x.type == LONG && y.type == LONG) || (x.type == DOUBLE && y.type == DOUBLE))
    {
        long a = x.dados.LONG < y.dados.LONG;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
    else if (x.type == LONG && y.type == DOUBLE)
    {
        long a = x.dados.LONG < y.dados.DOUBLE;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
    else if (x.type == DOUBLE && y.type == LONG)
    {
        long a = x.dados.DOUBLE < y.dados.LONG;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
    else if ((x.type == LONG && y.type == CHAR) || (x.type == CHAR && y.type == LONG) ||
             (x.type == CHAR && y.type == CHAR))
    {
        long a = x.dados.DOUBLE < y.dados.DOUBLE;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
    else if (x.type == DOUBLE && y.type == CHAR)
    {
        long a = x.dados.DOUBLE < y.dados.CHAR;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
    else if (x.type == CHAR && y.type == DOUBLE)
    {
        long a = x.dados.CHAR < y.dados.DOUBLE;
        MAKE_DADOS(x, LONG, a);
        push(s,x);
    } else if (x.type == LONG && y.type == ARRAY) {
        int i;
        STACK *nova = y.dados.ARRAY;
        STACK *nova2 = create_stack();
        nova->n_elems = nova->n_elems - x.dados.LONG + 1;
        for (i = x.dados.LONG; i > 0; i--)
        {
            push(nova2, top(nova));
            nova->n_elems++;
        }
        DATA p;
        MAKE_DADOS(p, ARRAY, nova2);
        push(s, p);
    } else if (x.type == STRING && y.type == STRING) {
        int i = 0;
        while (*x.dados.STRING != '\0' && *y.dados.STRING != '\0') {
            if (*x.dados.STRING < *y.dados.STRING) {
                i = 1;
                break;
            }
            else {
                i = 0;
                break;
            }
            x.dados.STRING++;
            y.dados.STRING++;
        } 
        DATA t;
        MAKE_DADOS(t,LONG,i);
        push(s,t);
    }
}

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma condição "menor".
 * 
 * @param s é apontador para a stack.
 *
 */

void menor(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    if ((x.type == LONG && y.type == LONG) || (x.type == DOUBLE && y.type == DOUBLE))
    {
        long a = x.dados.LONG > y.dados.LONG;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
    else if (x.type == LONG && y.type == DOUBLE)
    {
        long a = x.dados.LONG > y.dados.DOUBLE;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
    else if (x.type == DOUBLE && y.type == LONG)
    {
        long a = x.dados.DOUBLE > y.dados.LONG;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
    else if ((x.type == LONG && y.type == CHAR) || (x.type == CHAR && y.type == LONG) ||
             (x.type == CHAR && y.type == CHAR))
    {
        long a = x.dados.DOUBLE > y.dados.DOUBLE;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
    else if (x.type == DOUBLE && y.type == CHAR)
    {
        long a = x.dados.DOUBLE > y.dados.CHAR;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
    else if (x.type == CHAR && y.type == DOUBLE)
    {
        long a = x.dados.CHAR > y.dados.DOUBLE;
        MAKE_DADOS(x, LONG, a);
        push(s, x);
    }
    else if (x.type == LONG && y.type == ARRAY)
    {
        int i;
        STACK *nova = y.dados.ARRAY;
        STACK *nova2 = create_stack();
        //long t;
        //t = x.dados.LONG;
        for (i = 0; i <= x.dados.LONG; i++)
        {
            nova->n_elems = i;
            push(nova2, top(nova));
            //t--;
        }
        DATA p;
        MAKE_DADOS(p, ARRAY, nova2);
        push(s, p);
    }
    else if (x.type == STRING && y.type == STRING) {
        int i = 0;
        while (*x.dados.STRING != '\0' && *y.dados.STRING != '\0') {
            if (*x.dados.STRING > *y.dados.STRING) {
                i = 1;
                break;
            }
            else {
                i = 0;
                break;
            }
            x.dados.STRING++;
            y.dados.STRING++;
        } 
        DATA t;
        MAKE_DADOS(t,LONG,i);
        push(s,t);
    }
}

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma "negação".
 * 
 * @param s é apontador para a stack.

 */

void neg(STACK *s)
{
    DATA x = pop(s);
    long var;
    long a = x.dados.LONG;
    if (a == 1)
        var = 0;
    if (a == 0)
        var = 1;
    MAKE_DADOS(x, LONG, var)
    push(s, x);
}

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma operação conjuntiva com shortcut.
 * 
 * @param s é apontador para a stack.
 *
 */

void eshortcut(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    double var = 0;
    if ((x.type == LONG) && (y.type == LONG))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;
        if (b != 0)
            var = a;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == DOUBLE) && (y.type == DOUBLE))
    {
        double a = x.dados.DOUBLE;
        double b = y.dados.DOUBLE;
        if (b != 0)
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == LONG) && (y.type == DOUBLE))
    {
        long a = x.dados.LONG;
        double b = y.dados.DOUBLE;
        if (b != 0)
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == LONG))
    {
        double a = x.dados.DOUBLE;
        long b = y.dados.LONG;
        if (b != 0)
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    push(s, x);
}

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante uma operação disjuntiva com shortcut.
 * 
 * @param s é apontador para a stack.
 *
 */

void oushortcut(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    double var;
    if ((x.type == LONG) && (y.type == LONG))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;
        var = b;
        if (b == 0)
            var = a;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == DOUBLE) && (y.type == DOUBLE))
    {
        double a = x.dados.DOUBLE;
        double b = y.dados.DOUBLE;
        var = b;
        if (b == 0)
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == LONG) && (y.type == DOUBLE))
    {
        long a = x.dados.LONG;
        double b = y.dados.DOUBLE;
        var = b;
        if (b == 0)
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == LONG))
    {
        double a = x.dados.DOUBLE;
        long b = y.dados.LONG;
        var = b;
        if (b == 0)
            var = a;
        MAKE_DADOS(x, DOUBLE, var);
    }
    push(s, x);
}

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante a operação lógica "menor".
 * 
 * @param s é apontador para a stack.
 *
 */

void menorlog(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    double var;
    if ((x.type == LONG) && (y.type == LONG))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;
        var = a;
        if (b < a)
            var = b;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == LONG) && (y.type == DOUBLE))
    {
        long a = x.dados.LONG;
        double b = y.dados.DOUBLE;
        var = a;
        if (b < a)
            var = b;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == LONG))
    {
        double a = x.dados.DOUBLE;
        long b = y.dados.LONG;
        var = a;
        if (b < a)
            var = b;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == DOUBLE))
    {
        double a = x.dados.DOUBLE;
        double b = y.dados.DOUBLE;
        var = a;
        if (b < a)
            var = b;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == STRING) && (y.type == STRING))
    {
            if (strcmp(x.dados.STRING,y.dados.STRING) > 0) {
                MAKE_DADOS(x,STRING,y.dados.STRING);
            }
            else if (strcmp(x.dados.STRING,y.dados.STRING) <=  0){
                MAKE_DADOS(x,STRING,x.dados.STRING);
            }
    }
    push(s, x);
}

/** 
 * \brief Esta é a função que decide o comportamento a adotar consoante a operação lógica "maior".
 * 
 * @param s é apontador para a stack.
 *
 */

void maiorlog(STACK *s)
{
    DATA x = pop(s);
    DATA y = pop(s);
    double var;
    if ((x.type == LONG) && (y.type == LONG))
    {
        long a = x.dados.LONG;
        long b = y.dados.LONG;
        var = a;
        if (b > a)
            var = b;
        MAKE_DADOS(x, LONG, var);
    }
    else if ((x.type == LONG) && (y.type == DOUBLE))
    {
        long a = x.dados.LONG;
        double b = y.dados.DOUBLE;
        var = a;
        if (b > a)
            var = b;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == LONG))
    {
        double a = x.dados.DOUBLE;
        long b = y.dados.LONG;
        var = a;
        if (b > a)
            var = b;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == DOUBLE) && (y.type == DOUBLE))
    {
        double a = x.dados.DOUBLE;
        double b = y.dados.DOUBLE;
        var = a;
        if (b > a)
            var = b;
        MAKE_DADOS(x, DOUBLE, var);
    }
    else if ((x.type == STRING) && (y.type == STRING))
    {
            if (strcmp(x.dados.STRING,y.dados.STRING) < 0) {
                MAKE_DADOS(x,STRING,y.dados.STRING);
            }
            else if (strcmp(x.dados.STRING,y.dados.STRING) >=  0){
                MAKE_DADOS(x,STRING,x.dados.STRING);
            }
    }
    push(s, x);
}