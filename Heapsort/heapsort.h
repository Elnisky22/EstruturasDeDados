#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED
#define CAPACIDADE 10001

struct Heap {
   int tamanho;
   int vetor[CAPACIDADE];
};

typedef struct Heap MaxHeap;

int obtemFilhoMenor (MaxHeap* h, int filhoEsquerdo, int filhoDireito);
int obtemFilhoMaior (MaxHeap* h, int filhoEsquerdo, int filhoDireito);
int rebaixa (int i, MaxHeap* h);
int extraiMaximo(MaxHeap* h);
int promove (int i, MaxHeap* h);
int insere(int x, MaxHeap* h);
void incluiElementos(MaxHeap* maxHeap, int n);
int estaOrdenado(int vetor[CAPACIDADE], int n);
void imprimeVetor (int vetor[CAPACIDADE], int n);
void HeapSort (MaxHeap* maxHeap, int vetor[CAPACIDADE], int n);
void imprimeHeap(MaxHeap* h);

#endif // HEAPSORT_H_INCLUDED
