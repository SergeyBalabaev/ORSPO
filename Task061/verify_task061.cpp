#include <gtest/gtest.h>
#include "task061.hpp"

TEST(Test, CreateNode) {
    Node* node = create_node(42);
    EXPECT_EQ(node->data, 42);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev, nullptr);
    delete node;
}

TEST(Test, AppendNodes) {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    EXPECT_EQ(head->data, 10);
    EXPECT_EQ(head->next->data, 20);
    EXPECT_EQ(head->next->next->data, 30);
    delete_list(head);
}

TEST(Test, BackwardTraversal) {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    Node* tail = head->next->next;
    EXPECT_EQ(tail->prev->data, 20);
    EXPECT_EQ(tail->prev->prev->data, 10);
    delete_list(head);
}
