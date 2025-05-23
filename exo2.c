#include<stdio.h>
#include"trees.h"

int countNode(TreeNode* root){
    int sum = 0 ;
    if (root == NULL) return 0;
   return 1 + countNode(getLeft(root))+ countNode(getRight(root));

}

int main(){

    TreeNode* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 1);
    root = insert(root, 8);
    root = insert(root, 13);
    root = insert(root, 17);
    root = insert(root, 30);

    printf("the total num of nodes: %d" , countNode(root));
}