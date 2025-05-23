#include <stdio.h>
#include "trees.h"



// Function to insert a node in the BST

// Function to find the minimum value node in a BST
TreeNode* findMin(TreeNode* root) {
    while (getLeft(root) != NULL) {
        root = getLeft(root);
    }
    return root;
}

// Function to delete a node in the BST
TreeNode* delete(TreeNode* root, int value) {
    if (root == NULL) {
        return root; // Node not found
    }

    // Search for the node to be deleted
    if (value < getValue(root)) {
        setLeft(root, delete(getLeft(root), value));
    } else if (value > getValue(root)) {
        setRight(root, delete(getRight(root), value));
    } else {
        // Node to be deleted found

        // Case 1: Node has no children (leaf node)
        if (getLeft(root) == NULL && getRight(root) == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node has one child
        else if (getLeft(root) == NULL) {
            TreeNode* temp = getRight(root);
            free(root);
            return temp;
        } else if (getRight(root) == NULL) {
            TreeNode* temp = getLeft(root);
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        else {
            TreeNode* temp = findMin(getRight(root)); // In-order successor
            setValue(root, getValue(temp)); // Replace value with successor's value
            setRight(root, delete(getRight(root), getValue(temp))); // Delete successor
        }
    }

    return root;
}

// Function to draw the binary tree vertically (top to bottom)
void drawTree(TreeNode* root, int space) {
    if (root == NULL) {
        return;
    }

    // Increase space between levels for better visualization
    space += 5;

    // First, print the right subtree
    drawTree(getRight(root), space);

    // Print the current node with indentation
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");  // Indentation for each level of depth
    }
    printf("%d\n", getValue(root));

    // Then, print the left subtree
    drawTree(getLeft(root), space);
}

int main() {
    TreeNode* root = NULL;

    // Insert nodes into the BST
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

    // Print the tree before deletion
    printf("Binary Search Tree (before deletion):\n");
    drawTree(root, 0);

    // Delete a node (e.g., 20)
    root = delete(root, 20);

    // Print the tree after deletion
    printf("\nBinary Search Tree (after deleting 20):\n");
    drawTree(root, 0);

    // Delete another node (e.g., 3)
    root = delete(root, 3);

    // Print the tree after deleting another node
    printf("\nBinary Search Tree (after deleting 3):\n");
    drawTree(root, 0);

    // Free memory (important to avoid memory leaks)
    free(root);
    return 0;
}
