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
 * Problem: Search in Rotated Sorted Array (LeetCode 33)
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: Binary Search (Pivot Search + Subarray Binary Search)
 * Why/Skill: Identify sorted half & pivot comparison in O(log N)
 * 
 * Complexity:
 * - Time Complexity: O(log N) logarithmic search time.
 * - Space Complexity: O(1) constant auxiliary space.
 */

class Solution {
public:
    // Pass 2 Strategy: Find pivot first, then search target in the valid sorted half
    int searchRotatedArrayPass2(vector<int> v, int target) {
        if (v.empty()) return -1;

        // Pass 1: Binary search for the pivot (smallest element)
        int left = 0;
        int right = v.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (v[mid] > v[right]) {
                left = mid + 1; // Pivot is in right half
            } else {
                right = mid;    // Pivot is at mid or left half
            }
        }

        int pivot = left;

        // Decide which sorted subarray to search based on target
        if (target <= v[v.size() - 1]) {
            left = pivot;
            right = v.size() - 1;
        } else {
            left = 0;
            right = pivot - 1;
        }

        // Pass 2: Standard Binary Search on selected subarray
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid] == target) {
                return mid;
            } else if (v[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }

    // Pass 1 Strategy: Direct 1-Pass Binary Search checking sorted half bounds
    int searchRotatedArrayPass1(vector<int> v, int target) {
        int left = 0;
        int right = v.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (v[mid] == target) return mid;

            // Check if left half is sorted
            if (v[left] <= v[mid]) {
                if (v[left] <= target && target < v[mid]) {
                    right = mid - 1; // Target is in left half
                } else {
                    left = mid + 1;  // Target is in right half
                }
            } else {
                // Right half must be sorted
                if (v[mid] < target && target <= v[right]) {
                    left = mid + 1;  // Target is in right half
                } else {
                    right = mid - 1; // Target is in left half
                }
            }
        }

        return -1;
    }
};

int main() {
    cout << "Running No. 18: Search in Rotated Sorted Array..." << endl;
    Solution solver;
    
    // Test Case 1: Standard user example (Pass 2)
    vector<int> nums1 = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    assert(solver.searchRotatedArrayPass2(nums1, 3) == 7);
    cout << "Test Case 1 Passed (Pass 2): search(3) -> index 7" << endl;

    // Test Case 2: Target is the last element (Pass 2)
    assert(solver.searchRotatedArrayPass2(nums1, 4) == 8);
    cout << "Test Case 2 Passed (Pass 2): search(4) -> index 8" << endl;

    // Test Case 3: Pass 1 verification
    assert(solver.searchRotatedArrayPass1(nums1, 3) == 7);
    cout << "Test Case 3 Passed (Pass 1): search(3) -> index 7" << endl;

    // Test Case 4: LeetCode example (Pass 1)
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    assert(solver.searchRotatedArrayPass1(nums2, 0) == 4);
    cout << "Test Case 4 Passed (Pass 1): search(0) -> index 4" << endl;

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}
