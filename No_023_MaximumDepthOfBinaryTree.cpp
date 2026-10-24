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
    int maxDepth(TreeNode* current){
        // If current is nullptr then return 0
        if (current==nullptr){
            return 0;
        }
        else{
            // Check the maxdepth of left subtree
            int left=maxDepth(current->left);
            // Check the max depth of right subtree
            int right=maxDepth(current->right);
            // Check the which is greater and pass it
            return 1+max(left,right);
        }
    
    // int maxDepthOfTree(TreeNode*root){
    //     maxDepth
    // }
    }
};


int main() {
    cout << "Running No. 23: Maximum Depth of Binary Tree..." << endl;
    Solution solver;

    // Add test cases here
    // Creating the tree
    TreeNode* root1=new TreeNode(3);
    root1->left=new TreeNode(1);
    root1->right=new TreeNode(5);
    root1->right->left=new TreeNode(4);
    root1->right->right= new TreeNode(6);
    int out = solver.maxDepth(root1);
    cout<<endl<<"Max depth of the tree is "<<out;
    return 0;
}
