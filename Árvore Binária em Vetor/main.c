#include <stdio.h>
#include <stdlib.h>
#define TAM 15

//Função para encontrar o pai
int fPai(int v[], int i){
    int pai = v[(i/2)-1];
    return pai;
}

//Função para encontrar o filho à esquerda
int fFE(int v[], int i){
    int fE = v[(i*2)-1];
    return fE;
}

//Função para encontrar o filho à direita
int fFD(int v[], int i){
    int fD = v[i*2];
    return fD;
}

//Função para buscar um elemento na árvore
int busca(int v[], int x){
    for(int i=0;i<15;i++){
        if (v[i] == x){
            i++;
            return i;
        }
    }
    return -1;
}

int main(){
    int v[TAM] = {50, 30, 70, 22, 35, 61, 78, 8, 27, 33, 41, 52, 63, 74, 85};

    int pai, fE, fD;

    int op=0;
    do{
        int x, search;
        printf ("Insira um valor a ser buscado:\n");
        scanf ("%d", &x);

        search = busca(v, x);
        //printf ("O VALOR DE SEARCH EH: %d\n", search);

        //testar se o valor não existe
        if (search == -1){
            printf ("O valor nao existe na arvore.\n");
        }

        //testar se é a seed
        if (search == 1){
            printf ("O no buscado eh a seed.\n");
            fE = fFE(v, search);
            fD = fFD(v, search);
            printf ("Os filhos sao: FE %d | FD %d\n", fE, fD);
        }

        //testar se é uma folha
        if (search >= (TAM/2)+1){
            printf ("O valor buscado eh uma folha.\n");
            pai = fPai(v, search);
            printf ("O pai eh: %d\n", pai);
        }

        //resto
        if ((search > 1) && (search < (TAM/2)+1)){
            pai = fPai(v, search);
            fE = fFE(v, search);
            fD = fFD(v, search);
            printf ("O pai eh: %d\n", pai);
            printf ("Os filhos sao: FE %d | FD %d\n", fE, fD);
        }
        system("pause");
        system("cls");
        printf ("\nDeseja buscar outro numero? (1/0)");
        scanf ("%d", &op);
        system("cls");
        if (op == 0) op=-1;

    }while(op != -1);

    return 0;
}
