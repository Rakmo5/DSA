#include <iostream>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

/*
 * Problem: Validate Binary Search Tree (LeetCode 98)
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: BST / Tree DFS
 * Why/Skill: Exploit ordering invariant
 * 
 * Problem Statement:
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * (Solve this on LeetCode: https://leetcode.com/problems/validate-binary-search-tree/)
 * 
 * Complexity:
 * - Time Complexity: O(N) visits every node at most once.
 * - Space Complexity: O(H) recursion stack where H is the height of the tree.
 * 
 * Key Note:
 * Revisit again to strengthen mental model of recursive range boundaries (min_val, max_val).
 * When going left: window becomes (min_val, node->val).
 * When going right: window becomes (node->val, max_val).
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool validate(TreeNode* node, long long min_val, long long max_val) {
        if (node == nullptr) {
            return true;
        }

        // Strict inequalities: must be strictly within (min_val, max_val)
        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

        // Left child: (min_val, node->val)
        // Right child: (node->val, max_val)
        return validate(node->left, min_val, node->val) &&
               validate(node->right, node->val, max_val);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    cout << "Running No. 24: Validate Binary Search Tree..." << endl;
    Solution solver;

    // Test Case 1: Valid BST
    //         5
    //       /   \
    //      3     7
    //     / \   /
    //    1   4 6
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(4);
    root1->right = new TreeNode(7);
    root1->right->left = new TreeNode(6);

    cout << "Test 1 (Valid BST): ";
    assert(solver.isValidBST(root1) == true);
    cout << "PASSED" << endl;

    // Test Case 2: Invalid BST (Root is 5, but 4 is in its right subtree)
    //         5
    //       /   \
    //      1     4
    //           / \
    //          3   6
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    cout << "Test 2 (Invalid BST): ";
    assert(solver.isValidBST(root2) == false);
    cout << "PASSED" << endl;

    // Test Case 3: Single node tree
    TreeNode* root3 = new TreeNode(2147483647); // INT_MAX
    cout << "Test 3 (Single node INT_MAX): ";
    assert(solver.isValidBST(root3) == true);
    cout << "PASSED" << endl;

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}
