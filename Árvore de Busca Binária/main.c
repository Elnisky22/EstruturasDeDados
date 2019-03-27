#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "binarytree.h"

int main(){

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int op = -1, inst, busc;
    node *T = NULL;

    do{
        printf("         �RVORE DE BUSCA BIN�RIA\n=========================================\n|| 1- AUTO PREENCHER || 7- MENOR       ||\n|| 2-INSERIR         || 8- MAIOR       ||\n|| 3- BUSCAR         || 9- N�VEL N�    ||\n|| 4- PERCURSO       || 10- ALTURA TREE||\n|| 5- FOLHAS         || 11- REMOVER N� ||\n|| 6- QUANTIA N�S    || 12- BFT        ||\n=========================================\n   666- DESTRUIR �RVORE      0- SAIR\n");
        scanf ("%d", &op);
        system("cls");

        switch (op){
            case 1:
                printf ("Insira quantos valores quer na �rvore:\n");
                int y, tam;
                scanf ("%d", &tam);
                for (int i = 0; i < tam; i++){
                    y = rand() % 100;
                    insert_node(&T, y);
                }
                printf ("Auto preenchimento completado!\nA �rvore �:\n");
                breadthFirstTraversal(T);
            break;

            case 2:
                printf ("Insira um valor para incluir na �rvore:\n");
                scanf ("%d", &inst);
                insert_node(&T, inst);
                printf ("Valor inserido com sucesso!\n");
            break;

            case 3:
                printf ("Insira um valor para buscar na �rvore:\n");
                scanf ("%d", &busc);
                node *X = pesquisa_AB(T, busc);
                if (X == NULL) printf ("O valor %d n�o foi encontrado!\n", busc);
                else printf ("O valor %d foi encontrado!\n", X->value);
            break;

            case 4:
                printf ("Escolha uma forma para percorrer o percurso:\n1- Em Ordem\n2- Pr� Ordem\n3- P�s Ordem\n");
                int tipo;
                scanf("%d", &tipo);
                percurso(T, tipo);
            break;

            case 5:
                printf ("Buscando as folhas da �rvore...\n");
                leafs(T);
            break;

            case 6:
                printf ("A quantia de n�s na �rvore �: %d\n", nodeCount(T));
            break;

            case 7:
                printf ("O menor valor da �rvore �: ");
                node *Y = menor(T);
                if (Y != NULL) printf ("%d\n", Y->value);
                else printf ("�rvore vazia!\n");
            break;

            case 8:
                printf ("O maior valor da �rvore �: ");
                node *Z = maior(T);
                if (Z != NULL) printf ("%d\n", Z->value);
                else printf ("Arvore vazia!\n");
            break;

            case 9:
                printf ("Insira um valor para saber seu n�vel:\n");
                int busca, result;
                scanf("%d", &busca);
                result = nodeNivel(T, busca);
                if (result > -1) printf ("\nO n� buscado est� no n�vel %d.\n", result);
                    else printf ("O n� n�o existe na �rvore.\n");
            break;

            case 10:
                printf ("A altura da �rvore �: ");
                int w = altura(T);
                printf ("%d", w);
            break;

            case 11:
                printf ("Qual valor deseja excluir?\n");
                int k;
                scanf ("%d", &k);
                if (remove_AB(&T, k) != 0) printf ("N� %d removido.\n", k);
                else printf ("O valor n�o existe!\n");
            break;

            case 12:
                printf ("Breadth First Traversal:\n");
                breadthFirstTraversal(T);
            break;

            case 666:
                printf ("Destruindo a �rvore:\n");
            break;

            case 0:
                op = 0;
            break;

            default:
                printf ("Valor inv�lido!\n");
            break;
        }
        printf ("\n");
        system("pause");
        system("cls");

    }while(op != 0);

    return 0;
}
