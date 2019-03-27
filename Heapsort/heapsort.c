#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heapsort.h"

//Recebe um heap, os índices de dois filhos Esquerdo e Direito e devolve o inteiro que representa o menor valor
int obtemFilhoMenor (MaxHeap* h, int filhoEsquerdo, int filhoDireito){
	int minimo;
	int indiceMinimo;
	if (filhoEsquerdo <= (h->tamanho) && filhoDireito <= (h->tamanho)){
		minimo = h->vetor[filhoEsquerdo];
		indiceMinimo = filhoEsquerdo;
		if (minimo > h->vetor[filhoDireito]){
			minimo = h->vetor[filhoDireito];
			indiceMinimo = filhoDireito;
		}
		return indiceMinimo;
	}
	else
		if (filhoEsquerdo <= (h->tamanho) && filhoDireito > (h->tamanho)) return filhoEsquerdo;
	else
		if (filhoDireito <= (h->tamanho) && filhoEsquerdo > (h->tamanho)) return filhoDireito;
	else //Ambos são maiores que o heap: devolve valor que não aparecerá no heap->
		return CAPACIDADE + 1;
}

//Recebe um heap, os índices de dois filhos Esquerdo e Direito e devolve o inteiro que representa o maior valor
int obtemFilhoMaior (MaxHeap* h, int filhoEsquerdo, int filhoDireito){
	int maximo;
	int indiceMaximo;
	if (filhoEsquerdo <= (h->tamanho) && filhoDireito <= (h->tamanho)){
		maximo = h->vetor[filhoEsquerdo];
		indiceMaximo = filhoEsquerdo;
		if (maximo < h->vetor[filhoDireito]){
			maximo = h->vetor[filhoDireito];
			indiceMaximo = filhoDireito;
		}
		return indiceMaximo;
	}
	else
		if (filhoEsquerdo <= (h->tamanho) && filhoDireito > (h->tamanho)) return filhoEsquerdo;
	else
		if (filhoDireito <= (h->tamanho) && filhoEsquerdo > (h->tamanho)) return filhoDireito;
	else //Ambos são maiores que o heap: devolve valor que não aparecerá no heap->
      return CAPACIDADE + 1;
}

//Recebe um Heap e um índice i pertencente ao Heap. Devolve a nova posição do elemento que era inicialmente i
int rebaixa (int i, MaxHeap* h){
	int filhoEsquerdo;
	int filhoDireito;
	int filhoMaior;
	int filhoMenor;
	int aux;
	while (i <= (h->tamanho)){
		filhoEsquerdo = 2 * i;
		filhoDireito = 2 * i + 1;
		filhoMaior = obtemFilhoMaior(h, filhoEsquerdo, filhoDireito);
		filhoMenor = obtemFilhoMenor(h, filhoEsquerdo, filhoDireito);
		if ((filhoMaior <= h->tamanho) && (h->vetor[i] < h->vetor[filhoMaior])){
			aux = h->vetor[filhoMaior];
			h->vetor[filhoMaior] = h->vetor[i];
			h->vetor[i] = aux;
			i = filhoMaior;
		}
		else
			if ((filhoMenor <= h->tamanho) && (h->vetor[i] < h->vetor[filhoMenor])){
				aux = h->vetor[filhoMenor];
				h->vetor[filhoMenor] = h->vetor[i];
				h->vetor[i] = aux;
				i = filhoMenor;
			}
			else return i;
    }
	return i;
}

//Recebe um heap. Devolve o elemento que estava na raiz do heap
int extraiMaximo(MaxHeap* h){
	int maximo;
	if ((h->tamanho) > 1){
		maximo = h->vetor[1];
		h->vetor[1] = h->vetor[(h->tamanho)];
		(h->tamanho) = (h->tamanho) - 1;
		rebaixa (1, h);
	}
	else
		if (h->tamanho == 1){
			maximo = h->vetor[1];
			(h->tamanho) = 0;
		}
		else maximo = -1;
	return maximo;
}

//Devolve o novo valor de i após tentar realizar promoções ao valor que estava na posição inicial de i
int promove (int i, MaxHeap* h){
	int aux;
	while (i > 1){
		if (h->vetor[i] > h->vetor[ i / 2 ]){
			aux = h->vetor[i];
			h->vetor[i] = h->vetor[i / 2];
			h->vetor[i / 2] = aux;
			i = i / 2;
		}
		else return i;
	}
	return i;
}

//Recebe um Heap h e um vertice x. Insere x em h e devolve o índice de x em h.
int insere(int x, MaxHeap* h){
	int indiceX = -1;
	h->tamanho = (h->tamanho) + 1;

	if (h->tamanho < CAPACIDADE){
		h->vetor[h->tamanho] = x;
		indiceX = h->tamanho;
		indiceX = promove (indiceX, h);
	}
	return indiceX;
}


//Recebe um MaxHeap e um número n. Gera n números pseudo aleatórios e insere cada um no MaxHeap.
void incluiElementos(MaxHeap* maxHeap, int n){
	int i;
	int pseudoAleatorio;

	for (i = 0; i < n; i++){
		pseudoAleatorio = rand() % n;
		insere (pseudoAleatorio, maxHeap);
	}
}

//Recebe um vetor e seu tamanho n. Devolve 0 se não estiver em ordem não descrescente e devolve 1 se estiver
int estaOrdenado(int vetor[CAPACIDADE], int n){
	int i;
	for (i = 0; i < n - 1; i++){
		if (vetor[i] > vetor[i + 1]){
			return 0;
		}
	}
	return 1;
}

//Recebe um vetor e seu tamanho n. Imprime os elementos de 0 a n em v
void imprimeVetor (int vetor[CAPACIDADE], int n){
	int i;
	for (i = 0; i < n; i++){
		if (i % 10 == 0) printf ("\n");
		printf ("%5d ", vetor[i]);
	}
	printf ("\n");
}

//Recebe um MaxHeap, um vetor e um número n. Ordena os elementos do vetor de maneira não decrescente
void HeapSort (MaxHeap* maxHeap, int vetor[CAPACIDADE], int n){
	int i;
	for (i = n - 1; i >= 0; i--)
      vetor[i] = extraiMaximo(maxHeap);
}

//Recebe um heap h e imprime o conteúdo do heap
void imprimeHeap(MaxHeap* h){
   int i;
   printf ("Heap h\n");
   for (i = 1; i <= h->tamanho; i++) {
      printf ("heap[%d] : %d\n", i, h->vetor[i]);
   }
   printf ("\n");
}
