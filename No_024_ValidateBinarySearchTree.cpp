#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
 * Hints:
 * - If you get stuck, ask me for a hint in the chat!
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
public:
    bool isValidBST(TreeNode* root) {
        // TODO: Implement your solution here
        return true;
    }
};

int main() {
    cout << "Running No. 24: Validate Binary Search Tree..." << endl;
    Solution solver;
    // Add test cases here
    return 0;
}
