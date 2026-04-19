#ifndef AVL_H
#define AVL_H

typedef struct Node {
    int key;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

// API
Node* create_node(int key);
Node* insert(Node* root, int key);
Node* delete(Node* root, int key);
Node* search(Node* root, int key);

void inorder(Node* root);
void free_tree(Node* root);

int height(Node* n);
int get_balance(Node* n);

#endif