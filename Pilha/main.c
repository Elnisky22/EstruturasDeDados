#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    stack *p = new_stack(10);
    printf("INSERINDO ELEMENTOS NA PILHA:\n\n");
    push(5,p);
    push(15,p);
    push(25,p);
    push(35,p);
    push(45,p);
    push(55,p);
    printf("----- PILHA ORIGINAL ------\n\n");
    print(p);
    printf("\n Item removido da pilha: %d\n",pop(p));
    print(p);
    printf("\nRESULTADO BUSCA:\n");
    peek(45,p);
}
