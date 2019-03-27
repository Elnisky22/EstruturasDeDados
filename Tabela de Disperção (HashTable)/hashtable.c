#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

//Fun��o para alocar a Hash e setar os firsts para NULL
void alocaHash(Hash* hash){
	for (int i = 0; i < NCLASS;i++){
		hash[i].first = NULL;
	}
}

//Fun��o para alocar um n� j� com a String
node* alocaNo(char* str){
	node * newnode = (node *) malloc(sizeof(struct node));
	newnode->quantidade = 0;
	strcpy(newnode->palavra, str);
	newnode->next = NULL;
	printf ("Criando n� com a palavra \"%s\"...\n", newnode->palavra);
	return newnode;
}

//Fun��o para calcular a chave onde ser� inserida a String
int calculaKey(char* str){
	int key = 0;
	for (int i = 0; i < strlen(str); i++)
		key += str[i];
	return key % NCLASS;
}

//Fun��o para procurar se a palavra j� existe ou n�o
node* searchWord(char* str, node* no){
	node* auxn;
	auxn = no;
	printf ("Buscando a palavra \"%s\"...\n", str);
	while (auxn != NULL){
		if (strcmp(auxn->palavra, str) == 0){
			printf ("Palavra \"%s\" encontrada...\n", auxn->palavra);
			return auxn;
		}
		auxn = auxn->next;
	}
	printf ("Palavra \"%s\" n�o encontrada, criando...\n", str);
	node* newnode = alocaNo(str);
	return newnode;
}

//Fun��o para inserir uma nova palavra na lista da Hash
void inserirHash(char str[], Hash* hash){
	printf (" (Par�metro: %s, Chave: ", str);
	int key = calculaKey(str);
	printf ("%d)...\n", key);
	node* newnode = searchWord(str, hash[key].first);
	newnode->quantidade++;
	printf ("Incrementando contador de ocorr�ncias para %d...\n", newnode->quantidade);
	if (newnode->quantidade != 1){ printf("\n"); return;}

	printf ("Alocando n� \"%s\" na Hash[%d]...\n", newnode->palavra, key);
	if (hash[key].first == NULL){
		hash[key].first = newnode;
		printf ("N� alocado na primeira posi��o da Hash que estava vazia...\n\n");
	}
	else{
		newnode->next = hash[key].first;
		hash[key].first = newnode;
		printf ("N� alocado na primeira posi��o da Hash...\n\n");
	}
	printf("\n");
}

//Fun��o para imprimir a Hash com as palavras
void imprimirHash(Hash* hash){
	for (int i = 0; i < NCLASS; i++){
		node* auxn = hash[i].first;
		printf ("Hash[%d]: ", i);
		if (auxn == NULL) printf ("(vazia)\n");
		else{
			while (auxn != NULL){
				printf ("%s (ocorr�ncia %d), ", auxn->palavra, auxn->quantidade);
				auxn = auxn->next;
			}
		printf ("\n");
		}
	}
}
