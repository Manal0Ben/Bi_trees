#include "trees.h"
#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure and tree type

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


TreeNode* insert(TreeNode* root, int new) {
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

int searchTree(TreeNode* root, int value) {
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
void prefixe(TreeNode* root) {
    if (root== NULL) return;
    printf("Node value: %d\n", root->value);
    prefixe(root->left);
    prefixe(root->right);
}

// In-order 
void infixe(TreeNode* root) {
    if (root == NULL) return;
    infixe(root->left);
    printf("Node value: %d\n", root->value);
    infixe(root->right);
}

// Post-order
void postfix(TreeNode* root) {
    if (root == NULL) return;
    postfix(root->left);
    postfix(root->right);
    printf("Node value: %d\n", root->value);
}


void deleteNode(TreeNode* node) {
    if (node != NULL) {
        free(node);
    }
}

// Function to get the value stored in a node
int getValue(TreeNode* node) {
    return node ? node->value : -1;
}

// Function to set the value of a node
void setValue(TreeNode* node, int value) {
    if (node != NULL) {
        node->value = value;
    }
}

// Function to get the left child of a node
TreeNode* getLeft(TreeNode* node) {
    return node ? node->left : NULL;
}

// Function to set the left child for a given node
void setLeft(TreeNode* node, TreeNode* leftNode) {
    if (node != NULL) {
        node->left = leftNode;
    }
}

// Function to get the right child of a node
TreeNode* getRight(TreeNode* node) {
    return node ? node->right : NULL;
}

// Function to set the right child for a given node
void setRight(TreeNode* node, TreeNode* rightNode) {
    if (node != NULL) {
        node->right = rightNode;
    }
}

// Function to check if a tree is empty (i.e., root is NULL)
int isTreeEmpty(TreeNode* root) {
    return root == NULL;
}
