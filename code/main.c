#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//#include "parser.h"
//#include "stack.h"

void swap (char v[], int i, int j){
    int tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

char inverteArray (char v[], int N){
    int i,j;
    N = strlen(v);
    for(i=0,j = N-i-1 ;i<(N/2);i++){
        swap(v,i,j);
        return v[j];
    }
}

int pop (int stack[],int top, int item){
    if (top!=-1){
        item = stack[top];
        top = top - 1;
    }
}

void push (int stack[], int top, int MaxStack, int item){
    if (top != MaxStack - 1){
        top = top + 1;
        stack[top] = item;
    }
}

void show(char stack[])
{
    int top = strlen(stack) - 1;

    if((top!=-1))
    {
        for(int i=top;i>=0;--i)
            printf("%c",inverteArray(stack,strlen (stack) - 1));
    }
}


void parse (char * line){
    char *token;
    char *delims = " \t\n";
    int V[10000];
    int tam= -1,i ;

    for(token = strtok (line,delims); token != NULL ; token = strtok(NULL, delims)){
        char *sobra;
        long vall = strtol(token , &sobra, 10);
        if (strlen (sobra) == 0){
            push(V,tam,10000,vall);
            tam++;
        }
        else if (strcmp (token, "+") == 0){
            long x = pop(V,tam,x);
            tam--;
            long y = pop(V,tam,y);
            tam--;
            push(V,tam,10000,x+y);
            tam++;
        }
    }
    for (i=0;i<=tam;i++){
        printf("%d",V[i]);
    }
//    show(V);
}

int main(){
    char l [10000];

    assert( fgets (l ,10000,stdin) != NULL);
    assert ( l [strlen (l) - 1] == '\n'   );

    parse(l);
    return 0;
}