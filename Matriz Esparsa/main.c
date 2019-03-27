#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "header.h"

int main(){
    setlocale(LC_ALL,"Portuguese"); //função para uso de acentuação
    sparse_matrix*m = new_sparse_matrix(5, 5);
    int sw=0;
    while(sw != -1){
        printf ("O quê deseja fazer?\n1- Inserir valores\n2- Mostrar a matriz\n3- Encerrar\n");
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
                printf("Função inválida. Por favor, insira um número válido:\n");
            break;
        }
    }
    return 0;
}
