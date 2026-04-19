#include "../Unity/src/unity.h"
#include "list.h"

static void clear(Node** head) {
    free_list(*head);
    *head = NULL;
}

void test_push_back(void) {
    Node* head = NULL;

    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    TEST_ASSERT_EQUAL(1, head->data);
    TEST_ASSERT_EQUAL(2, head->next->data);
    TEST_ASSERT_EQUAL(3, head->next->next->data);

    // проверка prev (ключевое отличие!)
    TEST_ASSERT_NULL(head->prev);
    TEST_ASSERT_EQUAL(1, head->next->prev->data);

    clear(&head);
}

void test_insert_middle(void) {
    Node* head = NULL;

    push_back(&head, 1);
    push_back(&head, 3);

    insert_at(&head, 2, 1);

    TEST_ASSERT_EQUAL(2, head->next->data);
    TEST_ASSERT_EQUAL(1, head->next->prev->data);
    TEST_ASSERT_EQUAL(3, head->next->next->data);

    clear(&head);
}

void test_insert_head(void) {
    Node* head = NULL;

    push_back(&head, 2);
    insert_at(&head, 1, 0);

    TEST_ASSERT_EQUAL(1, head->data);
    TEST_ASSERT_EQUAL(2, head->next->data);
    TEST_ASSERT_EQUAL(1, head->next->prev->data);

    clear(&head);
}

void test_delete_middle(void) {
    Node* head = NULL;

    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    delete_value(&head, 2);

    TEST_ASSERT_EQUAL(1, head->data);
    TEST_ASSERT_EQUAL(3, head->next->data);
    TEST_ASSERT_EQUAL(1, head->next->prev->data);

    clear(&head);
}

void test_delete_head(void) {
    Node* head = NULL;

    push_back(&head, 1);
    push_back(&head, 2);

    delete_value(&head, 1);

    TEST_ASSERT_EQUAL(2, head->data);
    TEST_ASSERT_NULL(head->prev);

    clear(&head);
}

void test_find(void) {
    Node* head = NULL;

    push_back(&head, 10);
    push_back(&head, 20);

    Node* f = find(head, 20);

    TEST_ASSERT_NOT_NULL(f);
    TEST_ASSERT_EQUAL(20, f->data);

    clear(&head);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_push_back);
    RUN_TEST(test_insert_middle);
    RUN_TEST(test_insert_head);
    RUN_TEST(test_delete_middle);
    RUN_TEST(test_delete_head);
    RUN_TEST(test_find);

    return UNITY_END();
}