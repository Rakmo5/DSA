#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

/*
 * Problem: Subarray Sum Equals K
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: Prefix Sum + Hashing
 * Why/Skill: Prefix-state lookup
 * 
 * Problem Statement:
 * (Solve this on LeetCode: https://leetcode.com/problems/subarray-sum-equals-k/)
 * 
 * Hints:
 * - If you get stuck, ask me for a hint in the chat!
 */

class Solution {
public:
    int subArrayCount(vector<int>& v, int k) {
        int counter = 0;
        int sum = 0;
        unordered_map<int, int> pastSum;
        pastSum[0] = 1; // Base case: prefix sum of 0 has occurred once

        for (int num : v) {
            sum += num;
            
            // 1. Check if the required complement exists in past history
            if (pastSum.find(sum - k) != pastSum.end()) {
                counter += pastSum[sum - k];
            }
            
            // 2. Record this prefix sum for future elements
            pastSum[sum]++;
        }
        return counter;
    }
};

int main() {
    cout << "Running No. 10: Subarray Sum Equals K..." << endl;
    Solution solver;
    // Add test cases here
    vector<int>v={1,-1,1,-1};

    int counter = solver.subArrayCount(v,0);
    cout<< "Thier are "<<counter<<" sub arrays";
    return 0;
}
