#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "Fila.h"

Queue* newQueue(int tamanho){
    Queue *f = (Queue*) malloc(sizeof(Queue));
	f->capacidade = tamanho;
	f->dados = malloc (f->capacidade * sizeof(void *));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;
	return f;
}

void enQueue(Queue *f,void *valor){
	if(queueFull(f)){
		printf("erro fila cheia");
        return;
	}
	f->ultimo= (f->ultimo+1)%f->capacidade;
	f->dados[f->ultimo] = valor;
	f->nItens++;
}

void * deQueue(Queue *f){
    if(queueEmpty(f)){
        printf("erro pilha vazia");
        return NULL;
    }
	void *temp = f->dados[f->primeiro++%f->capacidade];
	f->nItens--;
	return temp;

}

int queueEmpty(Queue *f){
	return (f->nItens==0);
}

int queueFull(Queue *f){
	return (f->nItens == f->capacidade);
}

void imprimeQueue(Queue *f){
    if(!queueEmpty(f)){
        int i=f->primeiro-1;
        do{
            printf("%d\t",(int)f->dados[i++]);
            i=(i+1)%f->capacidade;
        }while(i != f->ultimo);
        printf("\n\n");
    }
}
