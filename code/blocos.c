/*#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "stack.h"
#include "blocos.h"
#include "parser.h"
//#include "operations.h"

#define MAKE_DADOS(var, TYPE, valor) \
    var.dados.TYPE = valor;          \
    var.type = TYPE;

void executaBloco(STACK* s,char* line){
    DATA x = pop(s);
    DATA y = pop(s);
    if (x.type == BLOCO && y.type == LONG){
        char *a = (char *)malloc((strlen(line) + 1) * sizeof(char));
        //printf("%d",length(x.dados.BLOCO));
        x.dados.BLOCO++;
        while(*x.dados.BLOCO != '}'){
            if (*x.dados.BLOCO != ' ') {
                
            }
             x.dados.BLOCO++;
        }
    }
}*/