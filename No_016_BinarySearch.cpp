#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
#include <cassert>

using namespace std;

/*
 * Problem: Binary Search (LeetCode 704)
 * Difficulty: Easy
 * Level: Level 1
 * Pattern: Binary Search (Search Space Halving)
 * Why/Skill: Safe mid calculation & logarithmic search bounds
 * 
 * Complexity:
 * - Time Complexity: O(log N) logarithmic search time.
 * - Space Complexity: O(1) constant auxiliary space.
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            // Safe mid calculation to prevent 32-bit integer overflow
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    cout << "Running No. 16: Binary Search..." << endl;
    Solution solver;
    
    // Test Case 1: Target present in odd length array
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    assert(solver.search(nums1, 9) == 4);
    cout << "Test Case 1 Passed: search(9) -> index 4" << endl;

    // Test Case 2: Target absent
    assert(solver.search(nums1, 2) == -1);
    cout << "Test Case 2 Passed: search(2) -> index -1" << endl;

    // Test Case 3: Target at the first element
    assert(solver.search(nums1, -1) == 0);
    cout << "Test Case 3 Passed: search(-1) -> index 0" << endl;

    // Test Case 4: Target at the last element
    assert(solver.search(nums1, 12) == 5);
    cout << "Test Case 4 Passed: search(12) -> index 5" << endl;

    // Test Case 5: Single element match
    vector<int> nums2 = {5};
    assert(solver.search(nums2, 5) == 0);
    cout << "Test Case 5 Passed: single element match -> index 0" << endl;

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}
