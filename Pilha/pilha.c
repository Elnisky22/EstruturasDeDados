#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

stack* new_stack(int size){
    stack *p =(stack*) malloc (sizeof(stack));
    p->items = (int *)  malloc(size* sizeof(int));
    p->top = -1;
    p->count = 0;
    p->max = size;
    return p;
}

int is_null(stack *p)
{
    return p == NULL;
}

int is_full(stack *p)
{
    return p->count == p->max;
}

int is_empty(stack *p)
{
    return p->top == -1;
}

void print(stack *p)
{
    int i;
    for(i= p->top;i>=0 ;i--){
        printf("   item[%d] = %d\n",i,p->items[i]);
    }
}

void push(int x,stack *p)
{
    if(is_null(p) || is_full(p)){
    return;
    }
    p->top++;
    p->items[p->top] = x;
    p->count++;
}

int pop(stack *p)
{
    int x;
    x = p->items[p->top];
    p->top--;
    p->count--;
    return x;
}

void peek(int i, stack *p)
{
    if(is_null(p) || is_empty(p)) return;
    int j,x;
    stack *tempPilha = new_stack(p->count);  //criacao de uma outra pilha temporaria.
    for(j= p->top; j>=0; j--){
        x = pop(p);
        if(x == i){
            printf(" %d Encontrado na posicao: %d\n",i,j);
        }
        push(x,tempPilha);
    }
    for(j=0; j<= tempPilha->top;j++) push(pop(tempPilha),p);
}
