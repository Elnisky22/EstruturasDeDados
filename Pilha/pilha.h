#ifndef PILHA_H
#define PILHA_H

typedef struct{
    int *items;
    int max;
    int count;
    int top;
} stack;

stack* new_stack(int size);
int is_null(stack *p);
int is_full(stack *p);
int is_empty(stack *p);
void clear(stack *p);
void print(stack *p);

void push(int x,stack *p);
int pop(stack *p);
void peek(int i,stack *p);

#endif // PILHA_H
