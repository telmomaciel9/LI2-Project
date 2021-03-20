#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"
//#include "stack.h"

void parse (char * line){
    char *token;
    char *delims = " \t\n";

    for(token = strtok (line,delims); token != NULL ; token = strtok(NULL, delims)){
        char *s;
        long vall = strtol(token , &s, 10);
        if (strlen (s) == 0){
            push(vall);
        }
        else if (strcmp (token, "+") == 0){
            long x = pop();
            long y = pop();
            push(x+y); 
        }
    }
    //display();
}

int main(){
    char l [10000];

    assert( fgets (l ,10000,stdin) != NULL);
    assert ( l [strlen (l) - 1] == '\n'   );

    parse(l);
    return 0;
}



