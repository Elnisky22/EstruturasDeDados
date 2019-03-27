#include <stdlib.h>
#include <stdio.h>
#include "encadeada.h"

//Cria��o da lista
list* new_list(int size){
    list *l =(list*) malloc(sizeof(list));
    l->count = 0;
    l->max = size;
    l->first = NULL;
    l->last = NULL;
    return l;
}

//Cria��o de n�s
node* create_node(int x){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = x;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}

//===========TESTES============
int is_empty_l(list *l){
    return (l->count == 0 || l->first == NULL);
}

int is_full_l(list *l){
  return l==NULL || l->max == -1 ?0 :l->count == l->max;
}

int is_null_l(list *l){
   return l == NULL;
}
//========ENDTESTES============

//Inserir na primeira posi��o
void insert_first(int x, list *l){
    if(is_null_l(l) || is_full_l(l))return;
    node* new_node = create_node(x);
    if(is_empty_l(l)){
        l->first = new_node;
        l->last = new_node;
    }
    else{
        new_node->next = l->first;
        new_node->previous = new_node;
        l->first = new_node;
    }
    l->count++;
}

//Inserir em qualquer posi��o
void insert_at(int x,int y,list *l){
    if(is_null_l(l) || is_full_l(l))return;
    if(is_empty_l(l) && y !=0)return;
    if(is_empty_l(l) && y == 0){
        insert_first(x,l);
        return;
    }
    node* new_node = create_node(x);
    int i=0;
    node* aux = l->first;
    while(i++ < y-1){
        aux = aux->next;
    }
    new_node->previous = aux;
    new_node->next = aux->next;
    aux->next = new_node;
    l->last = new_node;
    l->count++;
}

//Inserir na �ltima posi��o
void insert_last(int x, list *l){
    if(is_null_l(l) || is_full_l(l)) return;
    insert_at(x,l->count,l);
}

//Remover da primeira posi��o
int remove_first(list *l){
    if(is_null_l(l) || is_empty_l(l))return-1;
    node* aux = l->first;
    int x = aux->value;
    l->first = aux->next;
    l->count--;
    return x;
}

//Remover de qualquer posi��o
int remove_at(int y,list *l){
    if(is_null_l(l) || is_empty_l(l))return-1;
    int x;
    if(y == 0){
        remove_first(l);
    }
    if(y == l->count-1){
        remove_last(l);
    }
    else{
        node* aux = l->first;
        int i=0;
        while(i < y-1){
            aux = aux->next;
            i++;
        }
        aux->previous = aux;
        x = aux->value;
        aux->next = aux->next->next;
    }
    l->count--;
    return x;
}

//Remover da �ltima posi��o
int remove_last(list *l){
    if(is_null_l(l) || is_empty_l(l))return-1;
    node* aux = l->first;
    do{
        aux = aux->next;
        aux->previous = aux;
    }while(aux->next != l->last);
    int x = aux->next->value;
    aux->next = NULL;
    free(aux->next);
    l->last = aux->previous;
    l->count--;
    return x;
}

//Buscar na lista, RETORNANDO O �NDICE QUE FOI ENCONTRADO O VALOR
int search(int x, int j, list *l){
    node* aux = l->first;

    for(int i = 0; i < j; i++){
        aux = aux->next;
    }
    if(aux->value == x){
        return j;
    }
    return -1;
}

void print_l(list *l){
    if(is_empty_l(l))return;
    node* aux = l->first;
    int i=0;
    while(aux != NULL){
        printf(" ELEMENTO(%d) =  %d\n",i,aux->value);
        aux = aux->next;
        i++;
    }
}

void destroy_list(list **l){
    if(is_empty_l(*l))return;
    node* aux = (*l)->first;
    while(aux != NULL){
        node *del = aux;
        aux = aux->next;
        free(del);
    }
    free(*l);
    *l = NULL;
}
