#include <gtest/gtest.h>
#include "task064.hpp"

TEST(Test, NoCycle) {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    EXPECT_FALSE(has_cycle(head));
    delete_list(head);
}

TEST(Test, WithCycle) {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    create_cycle(head, 1);
    EXPECT_TRUE(has_cycle(head));
}

TEST(Test, CycleSelfLoop) {
    Node* head = nullptr;
    append(head, 1);
    create_cycle(head, 0);
    EXPECT_TRUE(has_cycle(head));
}

TEST(Test, SingleNodeNoCycle) {
    Node* head = nullptr;
    append(head, 42);
    EXPECT_FALSE(has_cycle(head));
    delete_list(head);
}
