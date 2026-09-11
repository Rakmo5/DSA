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
 * Problem: Valid Parentheses (LeetCode 20)
 * Difficulty: Easy
 * Level: Level 1
 * Pattern: Stack (LIFO Matching)
 * Why/Skill: Bracket matching & Stack empty guards
 * 
 * Complexity:
 * - Time Complexity: O(N) linear scan through the string of length N.
 * - Space Complexity: O(N) auxiliary space in the worst case (e.g. all opening brackets).
 */

class Solution {
public:
    bool validParenthesis(string s) {
        unordered_map<char, char> brackets = {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };
        stack<char> checker;

        for (char ch : s) {
            // If it is an opening bracket, push to stack
            if (ch == '{' || ch == '(' || ch == '[') {
                checker.push(ch);
            } else {
                // If closing bracket: guard against empty stack before calling top()
                if (checker.empty() || checker.top() != brackets[ch]) {
                    return false;
                }
                checker.pop();
            }
        }
        
        // Valid only if all opened brackets were successfully matched and popped
        return checker.empty();
    }
};

int main() {
    cout << "Running No. 14: Valid Parentheses..." << endl;
    Solution solver;
    
    // Test Case 1: Simple valid
    assert(solver.validParenthesis("()") == true);
    cout << "Test Case 1 Passed: '()' -> true" << endl;

    // Test Case 2: Multi-bracket valid
    assert(solver.validParenthesis("()[]{}") == true);
    cout << "Test Case 2 Passed: '()[]{}' -> true" << endl;

    // Test Case 3: Mismatched type
    assert(solver.validParenthesis("(]") == false);
    cout << "Test Case 3 Passed: '(]' -> false" << endl;

    // Test Case 4: Nested valid
    assert(solver.validParenthesis("([])") == true);
    cout << "Test Case 4 Passed: '([])' -> true" << endl;

    // Test Case 5: Out-of-order nested
    assert(solver.validParenthesis("([)]") == false);
    cout << "Test Case 5 Passed: '([)]' -> false" << endl;

    // Test Case 6: Starts with closing bracket (Empty stack guard)
    assert(solver.validParenthesis("]") == false);
    cout << "Test Case 6 Passed: ']' -> false" << endl;

    // Test Case 7: Only opening brackets
    assert(solver.validParenthesis("(((") == false);
    cout << "Test Case 7 Passed: '(((' -> false" << endl;

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}
