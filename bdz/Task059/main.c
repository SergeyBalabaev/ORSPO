#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Delete 20\n");
    root = delete(root, 20);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Delete 30\n");
    root = delete(root, 30);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Delete 50\n");
    root = delete(root, 50);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    int key = 60;
    Node* found = search(root, key);
    if (found)
        printf("Key %d found in the tree\n", key);
    else
        printf("Key %d not found\n", key);

    return 0;
}