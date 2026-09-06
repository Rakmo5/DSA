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
 * Problem: Longest Substring Without Repeating Characters (LeetCode 3)
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: Sliding Window (Variable Size)
 * Why/Skill: Dynamic window + set/map, generic template for any sequence
 * 
 * Problem Statement:
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Complexity:
 * - Time: O(N) where N is the length of the sequence. Each character is visited by front and back at most once.
 * - Space: O(min(N, M)) where M is the size of the character set (e.g. 26 for lowercase, 128 for ASCII).
 */

class Solution {
public:
    template <typename Container>
    int lengthOfLongestSubstring(const Container &seq) {
        if (seq.empty()) {
            return 0;
        }

        using ElementType = typename Container::value_type;
        unordered_set<ElementType> window;
        int longestLength = 0;
        int back = 0;

        for (int front = 0; front < seq.size(); front++) {
            // Shrink from back until duplicate is erased from the window
            while (window.count(seq[front])) {
                window.erase(seq[back]);
                back++;
            }

            // Insert current element
            window.insert(seq[front]);

            // Window [back ... front] is 100% unique!
            // Length is (front - back + 1) because both back and front are inclusive
            longestLength = max(longestLength, front - back + 1);
        }

        return longestLength;
    }
};

int main() {
    cout << "Running No. 12: Longest Substring Without Repeating Characters..." << endl;
    Solution solver;

    // Test 1: Standard string
    string s1 = "abcabcbb";
    cout << "Test 1 ('abcabcbb'): " << solver.lengthOfLongestSubstring(s1) << " (Expected: 3)" << endl;

    // Test 2: All duplicate characters
    string s2 = "bbbbb";
    cout << "Test 2 ('bbbbb'): " << solver.lengthOfLongestSubstring(s2) << " (Expected: 1)" << endl;

    // Test 3: Substring in middle
    string s3 = "pwwkew";
    cout << "Test 3 ('pwwkew'): " << solver.lengthOfLongestSubstring(s3) << " (Expected: 3)" << endl;

    // Test 4: Generic vector of integers
    vector<int> v1 = {1, 2, 3, 1, 2, 3, 4, 1};
    cout << "Test 4 (vector<int> {1,2,3,1,2,3,4,1}): " << solver.lengthOfLongestSubstring(v1) << " (Expected: 4)" << endl;

    // Test 5: Generic vector of chars
    vector<char> v2 = {'a', 'b', 'c', 'a', 'd', 'e', 'f'};
    cout << "Test 5 (vector<char> {'a','b','c','a','d','e','f'}): " << solver.lengthOfLongestSubstring(v2) << " (Expected: 6)" << endl;

    return 0;
}
