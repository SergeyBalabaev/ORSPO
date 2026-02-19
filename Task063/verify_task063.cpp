#include <gtest/gtest.h>
#include "task063.hpp"

TEST(Test, ReverseList) {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    head = reverse_list(head);
    EXPECT_EQ(head->data, 4);
    EXPECT_EQ(head->next->data, 3);
    EXPECT_EQ(head->next->next->data, 2);
    EXPECT_EQ(head->next->next->next->data, 1);
    delete_list(head);
}

TEST(Test, ReverseSingleElement) {
    Node* head = nullptr;
    append(head, 42);
    head = reverse_list(head);
    EXPECT_EQ(head->data, 42);
    EXPECT_EQ(head->next, nullptr);
    delete_list(head);
}

TEST(Test, ReverseEmpty) {
    Node* head = nullptr;
    head = reverse_list(head);
    EXPECT_EQ(head, nullptr);
}

TEST(Test, ReverseTwoElements) {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    head = reverse_list(head);
    EXPECT_EQ(head->data, 20);
    EXPECT_EQ(head->next->data, 10);
    delete_list(head);
}
