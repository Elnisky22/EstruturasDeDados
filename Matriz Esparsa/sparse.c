#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//Cria��o da Matriz dos ex br�di
sparse_matrix* new_sparse_matrix(int l, int c){
    sparse_matrix *m = (sparse_matrix*) malloc(sizeof(sparse_matrix));
    m->count = 0;
    m->sizeline = l;                      //tamanho das linhas
    m->sizecolum = c;                     //tamanho das colunas
    m->first = create_node(-1, -1, 22);   //criar um n� e alocar em first
    m->first->nextD = m->first;           // vv
    m->first->nextR = m->first;           //os apontadores de first apontam para ele mesmo
    return m;
}

//Cria��o de n�s para a matriz
node* create_node(int lin, int col, int x){
    node *newnode = (node *) malloc(sizeof(node));  //cria um novo n�
    //atribui��o de valores no novo n�
    newnode->value = x;
    newnode->poslin = lin;
    newnode->poscol = col;
    newnode->nextR = NULL;
    newnode->nextD = NULL;
    return newnode;
}

//==============================IN�CIO �REA DE TESTES============================================

//teste se est� vazia
int is_empty(sparse_matrix *m){
    return (m->first->nextD == m->first && m->first->nextR == m->first);
}

//teste se est� cheia
int is_full(sparse_matrix *m){
    return (m->count == m->sizeline*m->sizecolum);
}

//Teste se o n� existe no vetor de �ndices de linhas
node* test_node_down(int lin, sparse_matrix *m){
    int i=0;
    node *aux = m->first;
    do{
        if (aux->poslin == lin)
            return aux; //se j� existir, retorna
        aux = aux->nextD;
        i++;
    }while(i < m->sizeline);

    //cria��o caso n�o exista
    node *d = create_node(lin, -1, 55);
    node *aux2 = m->first;
    while (aux2->nextD != m->first){
        if ((aux2->nextD->poslin > d->poslin) || (aux2->nextD == m->first)){ //se nextD->poslin for maior que a posi��o da linha do n� d ou igual a -1 (first) ent�o...
            d->nextD = aux2->nextD;
            aux2->nextD = d;
            d->nextR = d;
            return d;
        }
        //if (aux2->nextD->poslin < d->poslin)
            aux2 = aux2->nextD;
    }
}

//Teste se o n� existe no vetor de �ndices de colunas
node* test_node_right(int col, sparse_matrix *m){
    int i=0;
    node *aux = m->first;
    do{
        if (aux->poscol == col)
            return aux;
        aux = aux->nextR;
        i++;
    }while(i < m->sizecolum);

     //cria��o caso n�o exista
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

//==============================FIM �REA DE TESTES============================================

//Inserir um valor na matriz
void set_value(sparse_matrix *m){
    if (is_full(m)){
        printf ("A matriz est� cheia!\n");
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
        if(((lin > m->sizeline-1) || (col > m->sizecolum-1)) || ((lin < 0) || (col < 0))){ //teste para verificar se as posi��es s�o v�lidas.
            printf ("Erro, posi��es inv�lidas!\n");
            system("pause");
            system("cls");
            test = 1;
        }else{
            test = 0;
        }
    }while(test != 0);

    node *nnode = create_node(lin, col, x); //criando o n� com o valor
    printf ("\nN� com o valor %d na posi��o (%d,%d) criado com sucesso!\n", nnode->value, nnode->poslin, nnode->poscol);

    //inser��o caso a lista esteja vazia
    if (is_empty(m)){
        node *r = create_node(-1, col, 666); //criando o n� da coluna
        node *d = create_node(lin, -1, 666); //criando o n� da linha

        r->nextR = m->first;
        r->nextD = nnode;

        d->nextD = m->first;
        d->nextR = nnode;

        m->first->nextR = r;
        m->first->nextD = d;

        nnode->nextR = d;
        nnode->nextD = r;

        m->count++;
        printf ("N� inserido com sucesso!\n");
        system("pause");
        system("cls");
        return;
    }
    else{
        node *d = test_node_down(lin, m); // testa se existe o n� da linha no vetor de �ndices, e caso n�o exista, cria-o
        //if (d->nextR == NULL) //se o nextR for igual a NULL, ent�o essa linha est� vazia
        //    d->nextR = d;     //o �ndice passa a apontar para ele mesmo

        node *r = test_node_right(col, m); //testa se existe o n� da coluna no vetor de �ndices, e caso n�o exista, cria-o
        //if (r->nextD == NULL) //se nextD for igual a NULL, ent�o essa coluna est� vazia
        //    r->nextD = r;     //o �ndice passa a apontar para ele mesmo

        //arrumando o vetor de �ndices de linha para apontar corretamente
        node *aux3 = d;
        while(aux3->nextR != d){
            if ((aux3->nextR->poslin > nnode->poslin) || (aux3->nextR == d)){ //se nextR do �ndice for ele mesmo, ent�o a linha est� vazia
                nnode->nextR = aux3->nextR;
                aux3->nextR = nnode; //o �ndice recebe o endere�o do valor
                printf ("ARRUMOU A LINHA 1\n");
            }
            //if (aux3->nextR->poslin < nnode->poslin)
                aux3 = aux3->nextR;
            //    printf ("ARRUMOU A LINHA 2\n");
        }

        //arrumando o vetor de �ndices de coluna para apontar corretamente
        node *aux4 = r;
        while(aux4->nextD != r){
            if ((aux4->nextD->poscol > nnode->poscol) || (aux4->nextD == r)){ //se nextD do �ndice for ele mesmo, ent�o a coluna est� vazia
                nnode->nextD = aux4->nextD; //o �ndice aponta para o n� do valor
                nnode->nextD = nnode; //n� do valor aponta para o n� do �ndice
                printf ("ARRUMOU A COLUNA 1\n");
            }
            //if (aux4->nextD->poscol < nnode->poscol)
                aux4 = aux4->nextD;
            //    printf ("ARRUMOU A COLUNA 2\n");
        }

        m->count++;
        printf ("N� inserido com sucesso!\n");
        system("pause");
        system("cls");
    }
}

//Impress�o da matriz dos ex br�di
void print_sparse_matrix(sparse_matrix *m){
    if (is_empty(m)){
        printf ("N�o h� matriz para ser impressa!\n");
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

//fun��o para destruir a matriz
void destroy_sparse_matrix(sparse_matrix **a){
    node *first = (*a)->first;
    node *rnode = first;
    node *back = first;
    while (rnode->nextD != NULL && rnode->nextR != NULL) { //enquanto rrnode n�o for nulo, ent�o ainda existe valores para destruir
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
