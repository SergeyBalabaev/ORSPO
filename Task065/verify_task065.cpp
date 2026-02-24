#include <gtest/gtest.h>
#include "task065.hpp"

TEST(Test, MergeTwoLists) {
    Node* head1 = nullptr;
    append(head1, 1);
    append(head1, 3);
    append(head1, 5);
    
    Node* head2 = nullptr;
    append(head2, 2);
    append(head2, 4);
    
    Node* merged = merge_lists(head1, head2);
    EXPECT_EQ(merged->data, 1);
    EXPECT_EQ(merged->next->data, 2);
    EXPECT_EQ(merged->next->next->data, 3);
    EXPECT_EQ(merged->next->next->next->data, 4);
    EXPECT_EQ(merged->next->next->next->next->data, 5);
    delete_list(merged);
}

TEST(Test, MergeEmptyWithNonEmpty) {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    append(head2, 1);
    append(head2, 2);
    
    Node* merged = merge_lists(head1, head2);
    EXPECT_EQ(merged->data, 1);
    EXPECT_EQ(merged->next->data, 2);
    delete_list(merged);
}

TEST(Test, MergeBothNonEmpty) {
    Node* head1 = nullptr;
    append(head1, 10);
    
    Node* head2 = nullptr;
    append(head2, 20);
    
    Node* merged = merge_lists(head1, head2);
    EXPECT_EQ(merged->data, 10);
    EXPECT_EQ(merged->next->data, 20);
    delete_list(merged);
}
