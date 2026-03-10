#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

int height(Node *n) {
///
};

Node* create_node(int key) {
///
};

Node* right_rotate(Node* y) {
///
};

Node* left_rotate(Node* x) {
///
};

int get_balance(Node* n) {
///
};

Node* insert(Node* node, int key) {
///
};

void inorder(Node* root) {
///
};

int main() {

    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    inorder(root);

    printf("\n");

    return 0;
}