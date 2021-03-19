#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"

int main(){
    char l [10000];

    assert( fgets (l ,10000,stdin) != NULL);
    assert ( l [strlen (l) - 1] == '\n'     );

    parse(l);
    return 0;
}

void parse (char * line){
    char *token;
    char *delims = " \t\n";

    for(token = strtok (line,delims); token != NULL ; token = strtok(NULL, delims)){
        printf("%s\n", token);
    }
}

