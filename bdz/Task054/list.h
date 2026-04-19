#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void push_back(Node** head, int value);
void insert_at(Node** head, int value, int index);
void delete_value(Node** head, int value);
Node* find(Node* head, int value);
void free_list(Node* head);

void print_list(Node* head);
void print_list_reverse(Node* head);

#endif