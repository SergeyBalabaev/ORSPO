#include <gtest/gtest.h>

#include "task060.hpp"

TEST(Test, CreateNode) {
    struct Node* n = create_node(42);
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(n->data, 42);
    EXPECT_EQ(n->next, nullptr);
    free_list(n);
}

TEST(Test, AppendNodes) {
    struct Node* head = create_node(1);
    head = append_node(head, 2);
    head = append_node(head, 3);

    struct Node* iter = head;
    EXPECT_EQ(iter->data, 1);
    iter = iter->next;
    EXPECT_EQ(iter->data, 2);
    iter = iter->next;
    EXPECT_EQ(iter->data, 3);
    iter = iter->next;
    EXPECT_EQ(iter, nullptr);

    free_list(head);
}
