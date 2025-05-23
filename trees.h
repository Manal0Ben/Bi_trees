#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>

//this library was made in the last TP session

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* insert(TreeNode* root, int new);
int searchTree(TreeNode* root, int value);
void prefixe(TreeNode* root);
void infixe(TreeNode* root);
void postfix(TreeNode* root);

//tree* createNode(int value);
TreeNode* createNode(int value);

void deleteNode(TreeNode* node);

int getValue(TreeNode* node);

void setValue(TreeNode* node, int value);

TreeNode* getLeft(TreeNode* node);

void setLeft(TreeNode* node, TreeNode* leftNode);

TreeNode* getRight(TreeNode* node);

void setRight(TreeNode* node, TreeNode* rightNode);

int isTreeEmpty(TreeNode* root);


#endif // TREE_H
