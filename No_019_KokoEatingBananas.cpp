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
 * Problem: Koko Eating Bananas (LeetCode 875)
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: Binary Search on Answer Space
 * Why/Skill: Binary searching the range of valid eating speeds [1 ... maxPile]
 * 
 * Complexity:
 * - Time Complexity: O(N * log(M)) where N is piles.length and M is max(piles).
 * - Space Complexity: O(1) constant auxiliary space.
 */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.empty()) return 0;

        int maxPile = 0;
        for (int p : piles) {
            maxPile = max(maxPile, p);
        }

        int low = 1;
        int high = maxPile;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Calculate total hours required at eating speed 'mid'
            long long totalHrs = 0;
            for (int p : piles) {
                totalHrs += (p + mid - 1) / mid; // Integer ceiling: ceil(p / mid)
            }

            // If speed 'mid' allows Koko to finish within 'h' hours, try a slower speed
            if (totalHrs <= h) {
                high = mid;
            } else {
                low = mid + 1; // Speed is too slow, must eat faster
            }
        }

        return low; // Convergent minimum valid speed
    }
};

int main() {
    cout << "Running No. 19: Koko Eating Bananas..." << endl;
    Solution solver;
    
    // Test Case 1: Standard user example
    vector<int> piles1 = {30, 11, 23, 4, 20};
    assert(solver.minEatingSpeed(piles1, 5) == 30);
    cout << "Test Case 1 Passed: piles = [30, 11, 23, 4, 20], h = 5 -> speed 30" << endl;

    // Test Case 2: Standard LeetCode example 1
    vector<int> piles2 = {3, 6, 7, 11};
    assert(solver.minEatingSpeed(piles2, 8) == 4);
    cout << "Test Case 2 Passed: piles = [3, 6, 7, 11], h = 8 -> speed 4" << endl;

    // Test Case 3: Standard LeetCode example 3
    assert(solver.minEatingSpeed(piles1, 6) == 23);
    cout << "Test Case 3 Passed: piles = [30, 11, 23, 4, 20], h = 6 -> speed 23" << endl;

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}
