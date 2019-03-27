#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//Criação da Matriz dos ex bródi
sparse_matrix* new_sparse_matrix(int l, int c){
    sparse_matrix *m = (sparse_matrix*) malloc(sizeof(sparse_matrix));
    m->count = 0;
    m->sizeline = l;                      //tamanho das linhas
    m->sizecolum = c;                     //tamanho das colunas
    m->first = create_node(-1, -1, 22);   //criar um nó e alocar em first
    m->first->nextD = m->first;           // vv
    m->first->nextR = m->first;           //os apontadores de first apontam para ele mesmo
    return m;
}

//Criação de nós para a matriz
node* create_node(int lin, int col, int x){
    node *newnode = (node *) malloc(sizeof(node));  //cria um novo nó
    //atribuição de valores no novo nó
    newnode->value = x;
    newnode->poslin = lin;
    newnode->poscol = col;
    newnode->nextR = NULL;
    newnode->nextD = NULL;
    return newnode;
}

//==============================INÍCIO ÁREA DE TESTES============================================

//teste se está vazia
int is_empty(sparse_matrix *m){
    return (m->first->nextD == m->first && m->first->nextR == m->first);
}

//teste se está cheia
int is_full(sparse_matrix *m){
    return (m->count == m->sizeline*m->sizecolum);
}

//Teste se o nó existe no vetor de índices de linhas
node* test_node_down(int lin, sparse_matrix *m){
    int i=0;
    node *aux = m->first;
    do{
        if (aux->poslin == lin)
            return aux; //se já existir, retorna
        aux = aux->nextD;
        i++;
    }while(i < m->sizeline);

    //criação caso não exista
    node *d = create_node(lin, -1, 55);
    node *aux2 = m->first;
    while (aux2->nextD != m->first){
        if ((aux2->nextD->poslin > d->poslin) || (aux2->nextD == m->first)){ //se nextD->poslin for maior que a posição da linha do nó d ou igual a -1 (first) então...
            d->nextD = aux2->nextD;
            aux2->nextD = d;
            d->nextR = d;
            return d;
        }
        //if (aux2->nextD->poslin < d->poslin)
            aux2 = aux2->nextD;
    }
}

//Teste se o nó existe no vetor de índices de colunas
node* test_node_right(int col, sparse_matrix *m){
    int i=0;
    node *aux = m->first;
    do{
        if (aux->poscol == col)
            return aux;
        aux = aux->nextR;
        i++;
    }while(i < m->sizecolum);

     //criação caso não exista
    node *r = create_node(-1, col, 55);
    node *aux2 = m->first;
    while (aux2->nextR != m->first){
        if ((aux2->nextR->poscol > r->poscol) || (aux2->nextR == m->first)){
            r->nextR = aux2->nextR;
            aux2->nextR = r;
            r->nextD = r;
            return r;
        }
        //if (aux2->nextR->poscol < r->poscol)
            aux2 = aux2->nextR;
    }
}

//==============================FIM ÁREA DE TESTES============================================

//Inserir um valor na matriz
void set_value(sparse_matrix *m){
    if (is_full(m)){
        printf ("A matriz está cheia!\n");
        system ("pause");
        system ("cls");
        return;
    }
    int lin, col, x, test=0;
    do{
        printf ("Insira a linha: ");
        scanf ("%d", &lin);
        printf ("Insira a coluna: ");
        scanf ("%d", &col);
        printf ("Insira o valor: ");
        scanf ("%d", &x);
        if(((lin > m->sizeline-1) || (col > m->sizecolum-1)) || ((lin < 0) || (col < 0))){ //teste para verificar se as posições são válidas.
            printf ("Erro, posições inválidas!\n");
            system("pause");
            system("cls");
            test = 1;
        }else{
            test = 0;
        }
    }while(test != 0);

    node *nnode = create_node(lin, col, x); //criando o nó com o valor
    printf ("\nNó com o valor %d na posição (%d,%d) criado com sucesso!\n", nnode->value, nnode->poslin, nnode->poscol);

    //inserção caso a lista esteja vazia
    if (is_empty(m)){
        node *r = create_node(-1, col, 666); //criando o nó da coluna
        node *d = create_node(lin, -1, 666); //criando o nó da linha

        r->nextR = m->first;
        r->nextD = nnode;

        d->nextD = m->first;
        d->nextR = nnode;

        m->first->nextR = r;
        m->first->nextD = d;

        nnode->nextR = d;
        nnode->nextD = r;

        m->count++;
        printf ("Nó inserido com sucesso!\n");
        system("pause");
        system("cls");
        return;
    }
    else{
        node *d = test_node_down(lin, m); // testa se existe o nó da linha no vetor de índices, e caso não exista, cria-o
        //if (d->nextR == NULL) //se o nextR for igual a NULL, então essa linha está vazia
        //    d->nextR = d;     //o índice passa a apontar para ele mesmo

        node *r = test_node_right(col, m); //testa se existe o nó da coluna no vetor de índices, e caso não exista, cria-o
        //if (r->nextD == NULL) //se nextD for igual a NULL, então essa coluna está vazia
        //    r->nextD = r;     //o índice passa a apontar para ele mesmo

        //arrumando o vetor de índices de linha para apontar corretamente
        node *aux3 = d;
        while(aux3->nextR != d){
            if ((aux3->nextR->poslin > nnode->poslin) || (aux3->nextR == d)){ //se nextR do índice for ele mesmo, então a linha está vazia
                nnode->nextR = aux3->nextR;
                aux3->nextR = nnode; //o índice recebe o endereço do valor
                printf ("ARRUMOU A LINHA 1\n");
            }
            //if (aux3->nextR->poslin < nnode->poslin)
                aux3 = aux3->nextR;
            //    printf ("ARRUMOU A LINHA 2\n");
        }

        //arrumando o vetor de índices de coluna para apontar corretamente
        node *aux4 = r;
        while(aux4->nextD != r){
            if ((aux4->nextD->poscol > nnode->poscol) || (aux4->nextD == r)){ //se nextD do índice for ele mesmo, então a coluna está vazia
                nnode->nextD = aux4->nextD; //o índice aponta para o nó do valor
                nnode->nextD = nnode; //nó do valor aponta para o nó do índice
                printf ("ARRUMOU A COLUNA 1\n");
            }
            //if (aux4->nextD->poscol < nnode->poscol)
                aux4 = aux4->nextD;
            //    printf ("ARRUMOU A COLUNA 2\n");
        }

        m->count++;
        printf ("Nó inserido com sucesso!\n");
        system("pause");
        system("cls");
    }
}

//Impressão da matriz dos ex bródi
void print_sparse_matrix(sparse_matrix *m){
    if (is_empty(m)){
        printf ("Não há matriz para ser impressa!\n");
        system("pause");
        system("cls");
        return;
    }
    node *first = m->first;
    node *rnode = first;
    node *dnode = first;
    for (int i = -1; i < m->sizeline; i++){
        for (int j = -1; j < m->sizecolum; j++){
            if (dnode != NULL && rnode != NULL && dnode->poslin == i && rnode->poscol == j){
                printf("(%-2d,%2d)=%-5d", i, j, rnode->value);
                rnode = rnode->nextR;
            }
            else{
               printf("(%-2d,%2d)=%-5d", i, j, i == -1 || j == -1 ? -1 : 0);
            }
        }
        printf("\n");
        if (dnode != NULL && dnode->poscol == i){
            dnode = dnode->nextD;
            rnode = dnode;
        }
    }
    system("pause");
    system("cls");
}

//função para destruir a matriz
void destroy_sparse_matrix(sparse_matrix **a){
    node *first = (*a)->first;
    node *rnode = first;
    node *back = first;
    while (rnode->nextD != NULL && rnode->nextR != NULL) { //enquanto rrnode não for nulo, então ainda existe valores para destruir
        back = rnode;
        if (rnode->nextD != NULL)
            rnode = rnode->nextD;
        else
            rnode = rnode->nextR;
        free(back);
        back = NULL;
    }
    free(*a);
    *a = NULL;
}
