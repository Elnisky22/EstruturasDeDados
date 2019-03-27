#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void main() {
    list *l = new_list(10);
    insert(0, l);
    insert(10, l);
    insert(20, l);
    insert(30, l);
    insert(40, l);
    insert(50, l);
    print(l);
    printf ("\n");
    printf("Item %d removido.\n", remove_at(2, l));
    print(l);
    printf ("\n");
    printf ("Item %d removido da ultima posicao.\n", remove_last(l));
    print(l);
    printf ("\n");
    printf("O item %d foi removido da primeira posicao.\n", remove_first(l));
    print(l);
    printf ("\n");
    printf ("Inserindo 28 na primeira posicao:\n");
    insert_first(28, l);
    print(l);
    printf ("\n");
    printf("Valor encontrado na posicao %d.\n", searchL(10, l));
    destroy_list(&l);
    printf("Lista destruida e sem dangling pointers?\n%d", l == NULL);
}
