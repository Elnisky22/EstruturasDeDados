#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "binarytree.h"
#include "Fila.h"

//inserir valores na �rvore
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

//pesquisar um �ndice na �rvore
node* pesquisa_AB(node *T, int x){
    if (T == NULL) return NULL;
    else if (T->value == x) return T;
        else if (T->value > x) return pesquisa_AB(T->left, x);
            else return pesquisa_AB(T->right, x);
}

//Fun��o para mostrar os percursos da �rvore
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

//fun��o para encontrar as folhas da �rvore
void leafs(node *T){
    if (T != NULL){
        if (T->left == NULL && T->right == NULL) printf("Encontrado uma folha: %d\n", T->value);
        else if (T->left != NULL) leafs(T->left);
            if (T->right != NULL) leafs(T->right);
    }
}

//fun��o para contar os n�s da �rvore
int nodeCount (node *T){
    if (T != NULL){
        return 1 + nodeCount(T->left) + nodeCount(T->right);
    } else return 0;
}

//fun��o para encontrar o menor valor da �rvore
node *menor (node *T){
    if (T == NULL) return NULL;
    else{
        if (T->left != NULL)
            menor(T->left);
        else
            return T;
    }
}

//fun��o para encontrar o maior valor da �rvore
node *maior (node *T){
    if (T == NULL) return NULL;
    else{
        if (T->right != NULL)
            maior(T->right);
        else
            return T;
    }
}

//fun��o para encontrar o n�vel do n�
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

//Fun��es para definir a altura da �rvore
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

//Fun��o para remover um item da �rvore
int remove_AB(node **T, int x){
    node *p;
    if (*T == NULL) return 0;
    else{
        if (x < (*T)->value) //valor menor ->sub�rvore esquerda
            remove_AB(&((*T)->left), x);
        else{
            if (x > (*T)->value) //valor maior ->sub�rvore direita
                remove_AB(&((*T)->right), x);
            else{ //valor encontrado
                if (((*T)->left == NULL) && ((*T)->right == NULL)){ //verifica se � folha
                    p = (*T);
                    free(p);
                    (*T) = NULL;
                    return 1;
                }
                else{ //agora verifica se n� tem um ou dois filhos
                    if ((*T)->right == NULL){ //Verifica se o n� tem filho da esquerda
                        p = (*T);
                        (*T) = (*T)->left;
                        free(p);
                        return 1;
                    }
                    else{ //Verifica se o n� tem filho da direita
                        if ((*T)->left == NULL){
                            p = (*T);
                            (*T) = (*T)->right;
                            free((p));
                            return 1;
                        }
                        else{ //Verifica se o n� tem ambos os filhos
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
