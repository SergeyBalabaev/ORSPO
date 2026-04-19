#include "../Unity/src/unity.h"
#include "list.h"
#include <stdlib.h>

static void clear(Node** head) {
    free_list(*head);
    *head = NULL;
}

void test_push_back(void) {
    Node* head = NULL;

    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL(1, head->data);
    TEST_ASSERT_EQUAL(2, head->next->data);
    TEST_ASSERT_EQUAL(3, head->next->next->data);

    clear(&head);
}

void test_insert_at_middle(void) {
    Node* head = NULL;

    push_back(&head, 1);
    push_back(&head, 3);

    insert_at(&head, 2, 1);

    TEST_ASSERT_EQUAL(1, head->data);
    TEST_ASSERT_EQUAL(2, head->next->data);
    TEST_ASSERT_EQUAL(3, head->next->next->data);

    clear(&head);
}

void test_insert_at_head(void) {
    Node* head = NULL;

    push_back(&head, 2);
    insert_at(&head, 1, 0);

    TEST_ASSERT_EQUAL(1, head->data);
    TEST_ASSERT_EQUAL(2, head->next->data);

    clear(&head);
}

void test_delete_value_middle(void) {
    Node* head = NULL;

    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    delete_value(&head, 2);

    TEST_ASSERT_EQUAL(1, head->data);
    TEST_ASSERT_EQUAL(3, head->next->data);
    TEST_ASSERT_NULL(head->next->next);

    clear(&head);
}

void test_delete_head(void) {
    Node* head = NULL;

    push_back(&head, 1);
    push_back(&head, 2);

    delete_value(&head, 1);

    TEST_ASSERT_EQUAL(2, head->data);

    clear(&head);
}

void test_find(void) {
    Node* head = NULL;

    push_back(&head, 10);
    push_back(&head, 20);

    Node* found = find(head, 20);

    TEST_ASSERT_NOT_NULL(found);
    TEST_ASSERT_EQUAL(20, found->data);

    clear(&head);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_push_back);
    RUN_TEST(test_insert_at_middle);
    RUN_TEST(test_insert_at_head);
    RUN_TEST(test_delete_value_middle);
    RUN_TEST(test_delete_head);
    RUN_TEST(test_find);

    return UNITY_END();
}
