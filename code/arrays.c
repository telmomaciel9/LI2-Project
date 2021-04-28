#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"
#include "stack.h"
#include "operations.h"
#include "logica.h"

#define MAKE_DADOS(var, TYPE, valor) \
    var.dados.TYPE = valor;          \
    var.type = TYPE;

/*void criaArray (STACK *s){
    int i;
    DATA c;
    STACK* a;
    DATA x = pop(s);
    a = create_stack();
    if (x.type == LONG){
        for(i=0 ; i < x.dados.LONG; i++){
           a = c.dados.ARRAY;
           
        }
    }
    if (x.type ==)
}*/