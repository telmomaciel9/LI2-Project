#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"
#include "stack.h"
//#include "operations.h"
//#include "logica.h"
#include "arrays.h"

#define MAKE_DADOS(var, TYPE, valor) \
    var.dados.TYPE = valor;          \
    var.type = TYPE;


void criaArray(STACK *s) {
    DATA x = pop(s);
    if (x.type == ARRAY){
        int cont;
        cont = x.dados.ARRAY -> n_elems;
        //printf("%d\n", x.dados.ARRAY -> n_elems);
        MAKE_DADOS(x,LONG,cont);
        push(s,x);
     }
     else {
        DATA y;
        STACK *a = create_stack();
        int i;
        for (i = 0; i < x.dados.LONG; i++) {
            MAKE_DADOS(y, LONG, i);
            push(a, y);
            //printf("%ld\n", y.dados.LONG);
        }
        MAKE_DADOS(y, ARRAY, a);
        push(s, y);
    }
}

void parseArray (STACK* s, char* line, char** rest, VAR* v)
{
    STACK* s_array = create_stack();
    char* seps = "[]";
    line = get_delimited(line,seps,rest);
    //printf("%s\n", line);
    parse(line,s_array,v);
    DATA t;
    MAKE_DADOS(t,ARRAY,s_array);
    push(s,t);
} 

