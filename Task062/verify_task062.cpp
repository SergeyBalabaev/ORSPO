#include <gtest/gtest.h>
#include "task062.hpp"

TEST(Test, SymmetricListOdd) {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 2);
    append(head, 1);
    EXPECT_TRUE(is_symmetric(head));
    delete_list(head);
}

TEST(Test, SymmetricListEven) {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 2);
    append(head, 1);
    EXPECT_TRUE(is_symmetric(head));
    delete_list(head);
}

TEST(Test, NotSymmetricList) {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    EXPECT_FALSE(is_symmetric(head));
    delete_list(head);
}

TEST(Test, SingleElement) {
    Node* head = nullptr;
    append(head, 42);
    EXPECT_TRUE(is_symmetric(head));
    delete_list(head);
}
