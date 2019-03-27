#include <stdio.h>
#include <stdlib.h>
#include "encadeada.h"

int main(){
    //Criação da Lista
    list *l = new_list(10);

    //Iserções na lista
    insert_first(10,l);
    insert_at(15,1,l);
    insert_at(20,2,l);
    insert_at(25,3,l);
    insert_at(20,4,l);
    insert_at(15,5,l);
    insert_at(20,6,l);
    insert_at(17,7,l);
    insert_at(33,8,l);
    insert_at(20,9,l);


    printf("\nA lista:\n");
    print_l(l);

    return 0;
}
