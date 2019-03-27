#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "header.h"

int main(){
    setlocale(LC_ALL,"Portuguese"); //fun��o para uso de acentua��o
    sparse_matrix*m = new_sparse_matrix(5, 5);
    int sw=0;
    while(sw != -1){
        printf ("O qu� deseja fazer?\n1- Inserir valores\n2- Mostrar a matriz\n3- Encerrar\n");
        scanf ("%d", &sw);
        switch (sw){
            case 1:
                system ("cls");
                set_value(m);
            break;

            case 2:
                system ("cls");
                print_sparse_matrix(m);
            break;

            case 3:
                sw = -1;
            break;

            default:
                system ("cls");
                printf("Fun��o inv�lida. Por favor, insira um n�mero v�lido:\n");
            break;
        }
    }
    return 0;
}
