#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heapsort.h"

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	srand(time(NULL));

	int n = 0;
	MaxHeap maxHeap;
	int vetor[CAPACIDADE] = {0, };
	maxHeap.tamanho = 0;

	printf ("*** Ordenação com HeapSort ***\n\n");
	while (n <= 0){
		printf ("Digite o tamanho do vetor a ser ordenado (0 < n <= 10000): ");
		scanf ("%d", &n);
	}

	if (n <= 10000){
		incluiElementos(&maxHeap, n);
		HeapSort (&maxHeap, vetor, n);
		printf ("Vetor Ordenado: ");

    if (estaOrdenado (vetor, n) == 1) printf ("Sim.\n");
    else printf("Não.\n");

    imprimeVetor (vetor, n);
    }
	else printf ("Forneça n no intervalo [1 - 10000].\n");

   return 0;
}
