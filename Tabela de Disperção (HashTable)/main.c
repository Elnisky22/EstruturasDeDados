#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

int main(void){

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	//Criação e inicialização da Hash com NCLASS posições
	Hash hash[NCLASS];
	alocaHash(hash);

	//Criar/apontar o arquivo
	char url[] = "texto.txt"; //caminho do arquivo
	FILE *arq;
	arq = fopen(url, "r"); //abre o arquivo em arq

	if (!arq) printf ("Abortar, deu ruim no arquivo!\n");
	else{
		char str[40]; //vetor que vai armazenar a palavra a ser adicionada na hash
		while (fscanf(arq, "%s", str) != EOF){
			printf ("Palavra \"%s\" encontrada", str);
			inserirHash(str, hash);
		}
		printf ("\n");
		imprimirHash(hash);
	}

	fclose(arq);
	return 0;
}
