#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#define NCLASS 10

typedef struct node{
	int quantidade;
	char palavra[40];
	struct node* next;
} node;

typedef struct Hash{
	struct node* first;
} Hash;

void alocaHash(Hash* hash);
node* alocaNo(char* str);
int calculaKey(char* str);
node* searchWord(char* str, node* no);
void inserirHash(char str[], Hash* hash);
void imprimirHash(Hash* hash);

#endif // HASHTABLE_H_INCLUDED
