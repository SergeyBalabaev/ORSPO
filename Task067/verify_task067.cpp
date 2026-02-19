#include <gtest/gtest.h>
#include "task067.hpp"
#include <cmath>

TEST(Test, CreateNode) {
    TreeNode* node = create_tree_node(42);
    EXPECT_EQ(node->data, 42);
    EXPECT_EQ(node->height, 1);
    delete node;
}

TEST(Test, InsertAndFind) {
    TreeNode* root = nullptr;
    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    
    EXPECT_EQ(find(root, 50), 1);
    EXPECT_EQ(find(root, 30), 1);
    EXPECT_EQ(find(root, 70), 1);
    EXPECT_EQ(find(root, 20), 1);
    EXPECT_EQ(find(root, 100), 0);
    delete_tree(root);
}

TEST(Test, BalancedTree) {
    TreeNode* root = nullptr;
    for (int i = 1; i <= 7; ++i) {
        insert(root, i);
    }
    int height = get_height(root);
    EXPECT_LE(height, 4);
    delete_tree(root);
}

TEST(Test, GetBalance) {
    TreeNode* root = nullptr;
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    
    int balance = get_balance(root);
    EXPECT_GE(balance, -1);
    EXPECT_LE(balance, 1);
    delete_tree(root);
}
