#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "binarytree.h"
#include "Fila.h"

//inserir valores na árvore
void insert_node(node **T, int x){
    if(*T == NULL){
        *T = malloc(sizeof(node));
        (*T)->left = NULL;
        (*T)->value = x;
        (*T)->right = NULL;
        return;
    }else if((*T)->value > x){
        return insert_node(&(*T)->left, x);
    }else return insert_node(&(*T)->right, x);
}

//pesquisar um índice na árvore
node* pesquisa_AB(node *T, int x){
    if (T == NULL) return NULL;
    else if (T->value == x) return T;
        else if (T->value > x) return pesquisa_AB(T->left, x);
            else return pesquisa_AB(T->right, x);
}

//Função para mostrar os percursos da árvore
void percurso(node *T, int tipo){
    switch(tipo){
        case 1:
            if (T != NULL){
                percurso(T->left, tipo);
                printf("%d ", T->value);
                percurso(T->right, tipo);
            }
        break;

        case 2:
            if (T != NULL){
                printf("%d ", T->value);
                percurso(T->left, tipo);
                percurso(T->right, tipo);
            }
        break;

        case 3:
            if (T != NULL){
                percurso(T->left, tipo);
                percurso(T->right, tipo);
                printf("%d ", T->value);
            }
        break;
    }
}

//função para encontrar as folhas da árvore
void leafs(node *T){
    if (T != NULL){
        if (T->left == NULL && T->right == NULL) printf("Encontrado uma folha: %d\n", T->value);
        else if (T->left != NULL) leafs(T->left);
            if (T->right != NULL) leafs(T->right);
    }
}

//função para contar os nós da árvore
int nodeCount (node *T){
    if (T != NULL){
        return 1 + nodeCount(T->left) + nodeCount(T->right);
    } else return 0;
}

//função para encontrar o menor valor da árvore
node *menor (node *T){
    if (T == NULL) return NULL;
    else{
        if (T->left != NULL)
            menor(T->left);
        else
            return T;
    }
}

//função para encontrar o maior valor da árvore
node *maior (node *T){
    if (T == NULL) return NULL;
    else{
        if (T->right != NULL)
            maior(T->right);
        else
            return T;
    }
}

//função para encontrar o nível do nó
int nodeNivel(node *T, int x){
    if (T == NULL) return -1;
    else{
        node *aux = T;
        int nivel = 1;
        while (aux != NULL && aux->value != x){
            if (x < aux->value)
                aux = aux->left;
            else
                aux = aux->right;
            nivel++;
        }
        if (aux == NULL) return -1;
        else return nivel;
    }
}

//Funções para definir a altura da árvore
int testeMaior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}
int altura(node *T){
   if((T == NULL) || (T->left == NULL && T->right == NULL))
       return 0;
   else
       return 1 + testeMaior(altura(T->left), altura(T->right));
}

//Função para remover um item da árvore
int remove_AB(node **T, int x){
    node *p;
    if (*T == NULL) return 0;
    else{
        if (x < (*T)->value) //valor menor ->subárvore esquerda
            remove_AB(&((*T)->left), x);
        else{
            if (x > (*T)->value) //valor maior ->subárvore direita
                remove_AB(&((*T)->right), x);
            else{ //valor encontrado
                if (((*T)->left == NULL) && ((*T)->right == NULL)){ //verifica se é folha
                    p = (*T);
                    free(p);
                    (*T) = NULL;
                    return 1;
                }
                else{ //agora verifica se nó tem um ou dois filhos
                    if ((*T)->right == NULL){ //Verifica se o nó tem filho da esquerda
                        p = (*T);
                        (*T) = (*T)->left;
                        free(p);
                        return 1;
                    }
                    else{ //Verifica se o nó tem filho da direita
                        if ((*T)->left == NULL){
                            p = (*T);
                            (*T) = (*T)->right;
                            free((p));
                            return 1;
                        }
                        else{ //Verifica se o nó tem ambos os filhos
                            p = maior((*T)->left);
                            (*T)->value = p->value;
                            remove_AB(&((*T)->left),p->value);
                            return 1;
                        }
                    }
                }
            }
        }
    }
}

void breadthFirstTraversal(node *T){
    if(T == NULL) return;
    Queue *queue = newQueue(pow(2, altura(T)));
    enQueue(queue,T);
    while(!queueEmpty(queue)){
        node *aux =deQueue(queue);
        if(aux->left != NULL)
            enQueue(queue, aux->left);
        if(aux->right != NULL)
            enQueue(queue, aux->right);
        printf("%d, ",aux->value);
    }
}
