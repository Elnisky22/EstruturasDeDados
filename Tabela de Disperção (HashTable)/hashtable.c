#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

//Função para alocar a Hash e setar os firsts para NULL
void alocaHash(Hash* hash){
	for (int i = 0; i < NCLASS;i++){
		hash[i].first = NULL;
	}
}

//Função para alocar um nó já com a String
node* alocaNo(char* str){
	node * newnode = (node *) malloc(sizeof(struct node));
	newnode->quantidade = 0;
	strcpy(newnode->palavra, str);
	newnode->next = NULL;
	printf ("Criando nó com a palavra \"%s\"...\n", newnode->palavra);
	return newnode;
}

//Função para calcular a chave onde será inserida a String
int calculaKey(char* str){
	int key = 0;
	for (int i = 0; i < strlen(str); i++)
		key += str[i];
	return key % NCLASS;
}

//Função para procurar se a palavra já existe ou não
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
	printf ("Palavra \"%s\" não encontrada, criando...\n", str);
	node* newnode = alocaNo(str);
	return newnode;
}

//Função para inserir uma nova palavra na lista da Hash
void inserirHash(char str[], Hash* hash){
	printf (" (Parâmetro: %s, Chave: ", str);
	int key = calculaKey(str);
	printf ("%d)...\n", key);
	node* newnode = searchWord(str, hash[key].first);
	newnode->quantidade++;
	printf ("Incrementando contador de ocorrências para %d...\n", newnode->quantidade);
	if (newnode->quantidade != 1){ printf("\n"); return;}

	printf ("Alocando nó \"%s\" na Hash[%d]...\n", newnode->palavra, key);
	if (hash[key].first == NULL){
		hash[key].first = newnode;
		printf ("Nó alocado na primeira posição da Hash que estava vazia...\n\n");
	}
	else{
		newnode->next = hash[key].first;
		hash[key].first = newnode;
		printf ("Nó alocado na primeira posição da Hash...\n\n");
	}
	printf("\n");
}

//Função para imprimir a Hash com as palavras
void imprimirHash(Hash* hash){
	for (int i = 0; i < NCLASS; i++){
		node* auxn = hash[i].first;
		printf ("Hash[%d]: ", i);
		if (auxn == NULL) printf ("(vazia)\n");
		else{
			while (auxn != NULL){
				printf ("%s (ocorrência %d), ", auxn->palavra, auxn->quantidade);
				auxn = auxn->next;
			}
		printf ("\n");
		}
	}
}
