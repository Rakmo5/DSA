#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

/*
 * Problem: Maximum Depth of Binary Tree (LeetCode 104)
 * Difficulty: Easy
 * Level: Level 1
 * Pattern: Tree DFS / Recursion
 * Why/Skill: Recursive subtree result
 * 
 * Problem Statement:
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * (Solve this on LeetCode: https://leetcode.com/problems/maximum-depth-of-binary-tree/)
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
    int maxDepth(TreeNode* root) {
        // TODO: Implement your solution here
        return 0;
    }
};

int main() {
    cout << "Running No. 23: Maximum Depth of Binary Tree..." << endl;
    Solution solver;
    // Add test cases here
    return 0;
}
