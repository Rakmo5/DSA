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
 * Problem: Find First and Last Position of Element in Sorted Array (LeetCode 34)
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: Binary Search (Boundary Binary Search)
 * Why/Skill: Leftmost and Rightmost boundary search in O(log N)
 * 
 * Complexity:
 * - Time Complexity: O(log N) logarithmic search time.
 * - Space Complexity: O(1) constant auxiliary space.
 */

class Solution {
public:
    int leftMost(const vector<int>& v, int element, int mid, int left) {
        int right = mid;
        int leftmost = mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (v[mid] == element) {
                right = mid - 1;
                leftmost = mid;
            } else {
                left = mid + 1;
            }
        }
        return leftmost;
    }

    int rightMost(const vector<int>& v, int element, int mid, int right) {
        int left = mid;
        int rightmost = mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (v[mid] == element) {
                left = mid + 1;
                rightmost = mid;
            } else {
                right = mid - 1;
            }
        }
        return rightmost;
    }

    pair<int, int> firstAndLast(vector<int> v, int element) {
        if (v.empty()) return {-1, -1};

        int left = 0;
        int right = v.size() - 1;
        pair<int, int> p = {-1, -1};

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid] == element) {
                p.first = leftMost(v, element, mid, left);
                p.second = rightMost(v, element, mid, right);
                return p;
            } else if (v[mid] < element) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {-1, -1};
    }
};

int main() {
    cout << "Running No. 17: Find First and Last Position of Element in Sorted Array..." << endl;
    Solution solver;
    
    // Test Case 1: Multiple occurrences
    pair<int, int> res1 = solver.firstAndLast({1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 4}, 2);
    assert(res1.first == 5 && res1.second == 9);
    cout << "Test Case 1 Passed: {1,1,1,1,1,2,2,2,2,2,3,4}, target 2 -> [" << res1.first << ", " << res1.second << "]" << endl;

    // Test Case 2: Standard LeetCode example
    pair<int, int> res2 = solver.firstAndLast({5, 7, 7, 8, 8, 10}, 8);
    assert(res2.first == 3 && res2.second == 4);
    cout << "Test Case 2 Passed: {5, 7, 7, 8, 8, 10}, target 8 -> [" << res2.first << ", " << res2.second << "]" << endl;

    // Test Case 3: Target not present
    pair<int, int> res3 = solver.firstAndLast({5, 7, 7, 8, 8, 10}, 6);
    assert(res3.first == -1 && res3.second == -1);
    cout << "Test Case 3 Passed: target 6 -> [-1, -1]" << endl;

    // Test Case 4: Empty vector
    pair<int, int> res4 = solver.firstAndLast({}, 0);
    assert(res4.first == -1 && res4.second == -1);
    cout << "Test Case 4 Passed: empty vector -> [-1, -1]" << endl;

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}
