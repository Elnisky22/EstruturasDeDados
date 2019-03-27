#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdbool.h>

typedef struct{
    int count;
    int sizeline;
    int sizecolum;
    struct Node *first;
}sparse_matrix;

typedef struct Node{
    int value, poslin, poscol;
    struct Node *nextR;
    struct Node *nextD;
}node;

sparse_matrix* new_sparse_matrix(int m, int n); //criação da matriz
node* create_node(int lin, int col, int x); //criação de nós

int is_empty(sparse_matrix *m); //teste se vazia
int is_full(sparse_matrix *m); //teste se cheia
node* test_node_down(int lin, sparse_matrix *m); //teste de nós de índice linha
node* test_node_right(int col, sparse_matrix *m); //teste de nós de índice coluna

void set_value(sparse_matrix *m); //isnerção de valores na matriz
void clear_sparce_matrix(sparse_matrix *m); //limpeza da matriz
int get_value(int i, int j); //busca de valores na matriz
void print_sparse_matrix(sparse_matrix *m); //printagem da matriz
sparse_matrix *add_sparse_matrix(sparse_matrix *a, sparse_matrix *b);   //soma
sparse_matrix *multiply_sparse_matrix(sparse_matrix *a, sparse_matrix *b);  //multiplicação
void destroy_sparse_matrix(sparse_matrix **m); //destruição


#endif // HEADER_H_INCLUDED
