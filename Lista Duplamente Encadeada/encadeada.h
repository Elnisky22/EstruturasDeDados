#ifndef LIST_CHAINED_DOUBLE_H
#define LIST_CHAINED_DOUBLE_H
#include <stdbool.h>

typedef struct {
    struct Node *first;
    struct Node *last;
    int count;
    int max;
}list;

typedef struct Node{
    int value;
    struct Node *next;
    struct Node *previous;
}node;

list* new_list(int size);
node* create_node(int x);
int is_null_l(list *l);
int is_empty_l(list *l);
int is_full_l(list *l);
void print_l(list *l);
void destroy_list(list **l);

int remove_first(list *l);
int remove_last(list *l);
int remove_at(int x,list *l);
void insert_first(int x, list *l);
void insert_at(int x,int y,list *l);
void insert_last(int x,list *l);
int search(int x,int j,list *l);

#endif // LIST_CHAINED_H
