#include <gtest/gtest.h>
#include "task066.hpp"

TEST(Test, CreateNode) {
    TreeNode* node = create_tree_node(42);
    EXPECT_EQ(node->data, 42);
    EXPECT_EQ(node->left, nullptr);
    EXPECT_EQ(node->right, nullptr);
    delete node;
}

TEST(Test, InsertAndFind) {
    TreeNode* root = nullptr;
    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    
    EXPECT_EQ(find(root, 50), 1);
    EXPECT_EQ(find(root, 30), 1);
    EXPECT_EQ(find(root, 70), 1);
    EXPECT_EQ(find(root, 20), 1);
    EXPECT_EQ(find(root, 100), 0);
    delete_tree(root);
}

TEST(Test, FindMin) {
    TreeNode* root = nullptr;
    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);
    
    EXPECT_EQ(find_min(root), 20);
    delete_tree(root);
}

TEST(Test, FindMax) {
    TreeNode* root = nullptr;
    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);
    
    EXPECT_EQ(find_max(root), 80);
    delete_tree(root);
}
