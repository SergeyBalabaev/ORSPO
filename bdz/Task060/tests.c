#include "../Unity/src/unity.h"
#include "tree.h"

Node* root;

void test_insert_balance(void) {
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);

    TEST_ASSERT_EQUAL(20, root->key); // проверка балансировки
}

void test_search(void) {
    root = insert(root, 10);
    root = insert(root, 5);

    TEST_ASSERT_NOT_NULL(search(root, 5));
    TEST_ASSERT_NULL(search(root, 999));
}

void test_delete(void) {
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);

    root = delete(root, 10);

    TEST_ASSERT_NULL(search(root, 10));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_insert_balance);
    RUN_TEST(test_search);
    RUN_TEST(test_delete);

    return UNITY_END();
}