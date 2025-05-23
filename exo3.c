#include<stdio.h>
#include "trees.h"

int depth(TreeNode* root){

    if (root==NULL) return 0;
    int Hleft = depth(root->left);
    int Hright = depth(root->right);

    return 1 + (Hleft > Hright ? Hleft : Hright);
}

int main() {
    TreeNode* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);

    printf("Height of the binary tree: %d\n", depth(root));

    return 0;
}