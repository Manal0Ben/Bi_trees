#include "trees.h"
#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure and tree type

// Function to create a new node
tree createNode(int val) {
    tree a = (tree)malloc(sizeof(Node));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;  
    }
    a->value = val;
    a->left = NULL;
    a->right = NULL;
    return a; 
}

tree insert(tree root, int new) {
    if (root == NULL) {
        return createNode(new); 
    }
    else if (new < root->value) {
        root->left = insert(root->left, new); 
    } else if (new > root->value) {
        root->right = insert(root->right, new); 
    }
    return root; 
}

int searchTree(tree root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->value == value) {
        return 1; 
    }
    if (value < root->value) {
        return searchTree(root->left, value); 
    } else {
        return searchTree(root->right, value); 
    }
}


// Pre-order
void prefixe(tree root) {
    if (root== NULL) return;
    printf("%d \n ", root->value);
    prefixe(root->left);
    prefixe(root->right);
}

// In-order 
void infixe(tree root) {
    if (root == NULL) return;
    infixe(root->left);
    printf("%d \n ", root->value);
    infixe(root->right);
}

// Post-order
void postfix(tree root) {
    if (root == NULL) return;
    postfix(root->left);
    postfix(root->right);
    printf("%d \n", root->value);
}
