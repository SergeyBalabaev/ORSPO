#pragma once

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int value);
void push_back(Node** head, int value);
void insert_at(Node** head, int value, int index); 
void delete_value(Node** head, int value);
Node* find(Node* head, int value);
void print_list(Node* head);
void free_list(Node* head);

