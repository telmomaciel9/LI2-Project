/**
 * @file main.c 
 * 
 * Ficheiro que contém a função principal do programa.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"
//#include "variables.h"

/**
 *  \brief Esta é a função principal do programa.
 * 
 * 
 * 
 * @returns O valor 0.
 */

int main()
{
    VAR *v = init_variables();
    char l[10000];
    STACK *s = create_stack();

    assert(fgets(l, 10000, stdin) != NULL);
    assert(l[strlen(l) - 1] == '\n');
    parse(l, s, v);

    print_stack(s);

    putchar('\n');
}