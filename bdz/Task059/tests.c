#include "../Unity/src/unity.h"
#include "tree.h"

Node* root = NULL;


// --- TESTS ---

void test_insert_and_search(void) {
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);

    TEST_ASSERT_NOT_NULL(search(root, 10));
    TEST_ASSERT_NOT_NULL(search(root, 5));
    TEST_ASSERT_NOT_NULL(search(root, 15));
    TEST_ASSERT_NULL(search(root, 999));
}

void test_delete_leaf(void) {
    root = insert(root, 10);
    root = insert(root, 5);

    root = delete(root, 5);

    TEST_ASSERT_NULL(search(root, 5));
}

void test_delete_root(void) {
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);

    root = delete(root, 10);

    TEST_ASSERT_NULL(search(root, 10));
}

// --- RUNNER ---

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_insert_and_search);
    RUN_TEST(test_delete_leaf);
    RUN_TEST(test_delete_root);

    return UNITY_END();
}