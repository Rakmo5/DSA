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
 * Problem: Permutation in String (LeetCode 567)
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: Sliding Window + Fixed-Size Frequency Matching
 * Why/Skill: Window counts & O(1) fixed alphabet comparisons
 * 
 * Complexity:
 * - Time Complexity: O(|s1| + |s2|) = O(N) linear time.
 *   Comparing two vectors of fixed size 26 takes O(26) = O(1) constant operations per slide.
 * - Space Complexity: O(1) auxiliary space (two fixed-size vectors of size 26).
 */

class Solution {
public:
    bool permutationInString(string s1, string s2) {
        // Guard: s1 cannot be a permutation in s2 if it is longer than s2
        if (s1.size() > s2.size()) {
            return false;
        }

        // 1. Build character frequency map for target s1
        vector<int> s1Vector(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            s1Vector[s1[i] - 'a']++;
        }

        // 2. Initialize the frequency map for the first sliding window in s2 (size = s1.size())
        vector<int> currentWindowVector(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            currentWindowVector[s2[i] - 'a']++;
        }

        // 3. Slide the window one character at a time
        for (int back = 0; back + s1.size() < s2.size(); back++) {
            // If current window matches s1 frequency distribution, permutation found!
            if (s1Vector == currentWindowVector) {
                return true;
            }
            
            // Slide: remove outgoing character on left, add incoming character on right
            currentWindowVector[s2[back] - 'a']--;
            currentWindowVector[s2[back + s1.size()] - 'a']++;
        }

        // 4. Final check for the last window position
        return s1Vector == currentWindowVector;
    }
};

int main() {
    cout << "Running No. 13: Permutation in String..." << endl;
    Solution solver;
    
    // Test Case 1: Standard positive case
    assert(solver.permutationInString("ab", "eidbaooo") == true);
    cout << "Test Case 1 Passed: ('ab', 'eidbaooo') -> true" << endl;

    // Test Case 2: Standard negative case
    assert(solver.permutationInString("ab", "eidboaoo") == false);
    cout << "Test Case 2 Passed: ('ab', 'eidboaoo') -> false" << endl;

    // Test Case 3: Permutation at the very end
    assert(solver.permutationInString("ab", "aachba") == true);
    cout << "Test Case 3 Passed: ('ab', 'aachba') -> true" << endl;

    // Test Case 4: s1 longer than s2
    assert(solver.permutationInString("hello", "hi") == false);
    cout << "Test Case 4 Passed: ('hello', 'hi') -> false" << endl;

    // Test Case 5: Single character match
    assert(solver.permutationInString("a", "a") == true);
    cout << "Test Case 5 Passed: ('a', 'a') -> true" << endl;

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}
