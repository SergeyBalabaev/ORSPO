#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {
    Node* head = NULL;

    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    print_list(head);

    insert_at(&head, 99, 1);
    print_list(head);

    delete_value(&head, 2);
    print_list(head);

    Node* found = find(head, 99);
    if (found)
        printf("Found: %d\n", found->data);

    free_list(head);
    return 0;
}