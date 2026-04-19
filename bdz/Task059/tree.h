#ifndef BST_H
#define BST_H

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int key);
Node* insert(Node* root, int key);
Node* search(Node* root, int key);
Node* delete(Node* root, int key);

void inorder(Node* root);
void free_tree(Node* root);

#endif