#include <stdio.h>
#include "trees.h"

void preOrder(TreeNode* root){
    printf("%d" , root->value);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root ){
    inOrder(root->left);
    printf("%d" , root->value);
    inOrder(root->right);
}

void postOrder(TreeNode* root){
    postOrder(root->left);
    postOrder(root ->right);
    printf("%d" , root->value);
}

int main(){

    TreeNode* root = NULL;

   
}