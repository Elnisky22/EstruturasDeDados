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
        printf("         ÁRVORE DE BUSCA BINÁRIA\n=========================================\n|| 1- AUTO PREENCHER || 7- MENOR       ||\n|| 2-INSERIR         || 8- MAIOR       ||\n|| 3- BUSCAR         || 9- NÍVEL NÓ    ||\n|| 4- PERCURSO       || 10- ALTURA TREE||\n|| 5- FOLHAS         || 11- REMOVER NÓ ||\n|| 6- QUANTIA NÓS    || 12- BFT        ||\n=========================================\n   666- DESTRUIR ÁRVORE      0- SAIR\n");
        scanf ("%d", &op);
        system("cls");

        switch (op){
            case 1:
                printf ("Insira quantos valores quer na árvore:\n");
                int y, tam;
                scanf ("%d", &tam);
                for (int i = 0; i < tam; i++){
                    y = rand() % 100;
                    insert_node(&T, y);
                }
                printf ("Auto preenchimento completado!\nA árvore é:\n");
                breadthFirstTraversal(T);
            break;

            case 2:
                printf ("Insira um valor para incluir na árvore:\n");
                scanf ("%d", &inst);
                insert_node(&T, inst);
                printf ("Valor inserido com sucesso!\n");
            break;

            case 3:
                printf ("Insira um valor para buscar na árvore:\n");
                scanf ("%d", &busc);
                node *X = pesquisa_AB(T, busc);
                if (X == NULL) printf ("O valor %d não foi encontrado!\n", busc);
                else printf ("O valor %d foi encontrado!\n", X->value);
            break;

            case 4:
                printf ("Escolha uma forma para percorrer o percurso:\n1- Em Ordem\n2- Pré Ordem\n3- Pós Ordem\n");
                int tipo;
                scanf("%d", &tipo);
                percurso(T, tipo);
            break;

            case 5:
                printf ("Buscando as folhas da árvore...\n");
                leafs(T);
            break;

            case 6:
                printf ("A quantia de nós na árvore é: %d\n", nodeCount(T));
            break;

            case 7:
                printf ("O menor valor da árvore é: ");
                node *Y = menor(T);
                if (Y != NULL) printf ("%d\n", Y->value);
                else printf ("Árvore vazia!\n");
            break;

            case 8:
                printf ("O maior valor da árvore é: ");
                node *Z = maior(T);
                if (Z != NULL) printf ("%d\n", Z->value);
                else printf ("Arvore vazia!\n");
            break;

            case 9:
                printf ("Insira um valor para saber seu nível:\n");
                int busca, result;
                scanf("%d", &busca);
                result = nodeNivel(T, busca);
                if (result > -1) printf ("\nO nó buscado está no nível %d.\n", result);
                    else printf ("O nó não existe na árvore.\n");
            break;

            case 10:
                printf ("A altura da árvore é: ");
                int w = altura(T);
                printf ("%d", w);
            break;

            case 11:
                printf ("Qual valor deseja excluir?\n");
                int k;
                scanf ("%d", &k);
                if (remove_AB(&T, k) != 0) printf ("Nó %d removido.\n", k);
                else printf ("O valor não existe!\n");
            break;

            case 12:
                printf ("Breadth First Traversal:\n");
                breadthFirstTraversal(T);
            break;

            case 666:
                printf ("Destruindo a árvore:\n");
            break;

            case 0:
                op = 0;
            break;

            default:
                printf ("Valor inválido!\n");
            break;
        }
        printf ("\n");
        system("pause");
        system("cls");

    }while(op != 0);

    return 0;
}
