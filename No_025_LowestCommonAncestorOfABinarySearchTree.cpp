#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

/*
 * Problem: Lowest Common Ancestor of a Binary Search Tree (LeetCode 235)
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: Tree / LCA
 * Why/Skill: Use BST property
 * 
 * Problem Statement:
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
 * (Solve this on LeetCode: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
 * 
 * Hints:
 * - If you get stuck, ask me for a hint in the chat!
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TODO: Implement your solution here
        return nullptr;
    }
};

int main() {
    cout << "Running No. 25: Lowest Common Ancestor of a Binary Search Tree..." << endl;
    Solution solver;
    // Add test cases here
    return 0;
}
