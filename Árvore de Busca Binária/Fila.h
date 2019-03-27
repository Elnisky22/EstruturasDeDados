#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct{
	int capacidade;
	int primeiro;
	int ultimo;
	int nItens;
    void **dados;
}Queue;

Queue * newQueue(int tamanho);

void enQueue(Queue *f,void *valor);

void * deQueue(Queue *f);

int queueEmpty(Queue *f);

int queueFull(Queue *f);

void imprimeQueue(Queue *f);

#endif // FILA_H_INCLUDED
