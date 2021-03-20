#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "parser.h"
//#include "stack.h"

char pop (char stack[],int top, char item){
    if (top!=-1){
        item = stack[top];
        top = top - 1;
    } 
    return item;
    }

void push (char stack[], int top, int MaxStack, char item){
     if (top != MaxStack - 1){
        top = top + 1;
        stack[top] = item;
     }
}

void show(char stack[],int top)
{
    top = (strlen (stack)) - 1;
     
    if((top!=-1))
    {
        for(int i=top;i>=0;--i)
            printf("%i",stack[i]);
    }
}


void parse (char * line){
    char *token;
    char *delims = " \t\n";

    for(token = strtok (line,delims); token != NULL ; token = strtok(NULL, delims)){
        char *s;
        long vall = strtol(token , &s, 10);
        if (strlen (s) == 0){
            push(line,(strlen(line)) - 1,10000,vall);
        }
        else if (strcmp (token, "+") == 0){
            long x = pop(line,(strlen(line)) - 1,x);
            long y = pop(line,(strlen(line)) - 1,y);
            long a = x+y;
            push(line,(strlen(line)) - 1,10000,x+y); 
        }
    }
    show(line,(strlen(line)) - 1);
}

int main(){
    char l [10000];

    assert( fgets (l ,10000,stdin) != NULL);
    assert ( l [strlen (l) - 1] == '\n'   );

    parse(l);
    return 0;
}



