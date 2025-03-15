#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>

//this library was made in the last TP session

typedef struct tree {
    int value;                 
    struct tree* left;  
    struct tree* right; 
} Node, *tree;

tree createNode(int val); 
tree insert(tree root, int new);
int searchTree(tree root, int value);
void prefixe(tree root);
void infixe(tree root);
void postfix(tree root);

#endif // TREE_H
