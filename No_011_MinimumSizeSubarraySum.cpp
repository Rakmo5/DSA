#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
 * Problem: Minimum Size Subarray Sum (LeetCode 209)
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: Sliding Window (Variable Size)
 * Why/Skill: Shrink/expand window with running sum
 * 
 * Problem Statement:
 * Given an array of positive integers nums and a positive integer target, return the minimal 
 * length of a subarray whose sum is greater than or equal to target. If there is no such 
 * subarray, return 0 instead.
 * 
 * Complexity:
 * - Time: O(N) since left and right pointers only move forward at most N times.
 * - Space: O(1) constant auxiliary memory.
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int currentSum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];

            // When sum reaches or exceeds target, shrink from left to find minimal length
            while (currentSum >= target) {
                minLen = min(minLen, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

int main() {
    cout << "Running No. 11: Minimum Size Subarray Sum..." << endl;
    Solution solver;

    vector<int> test1 = {2, 3, 1, 2, 4, 3};
    cout << "Test 1 ({2, 3, 1, 2, 4, 3}, target 7): " << solver.minSubArrayLen(7, test1) << " (Expected: 2)" << endl;

    vector<int> test2 = {2, 3, 4};
    cout << "Test 2 ({2, 3, 4}, target 7): " << solver.minSubArrayLen(7, test2) << " (Expected: 2)" << endl;

    vector<int> test3 = {1, 4, 4};
    cout << "Test 3 ({1, 4, 4}, target 4): " << solver.minSubArrayLen(4, test3) << " (Expected: 1)" << endl;

    vector<int> test4 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Test 4 ({1, 1, 1, 1, 1, 1, 1, 1}, target 11): " << solver.minSubArrayLen(11, test4) << " (Expected: 0)" << endl;

    return 0;
}
