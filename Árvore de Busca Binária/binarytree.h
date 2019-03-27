#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

typedef struct tree{
    int value;
    struct tree *left;
    struct tree *right;
} node;

void insert_node(node **T, int x);
void percurso(node *T, int tipo);
node* pesquisa_AB(node *T, int x);
void leafs(node *T);
int nodeCount (node *T);
node *menor (node *T);
node *maior (node *T);
int nodeNivel(node *T, int x);
int altura(node *T);
int remove_AB(node **T, int x);
void breadthFirstTraversal(node *T);

#endif // BINARYTREE_H_INCLUDED
