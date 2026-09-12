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
 * Problem: Min Stack (LeetCode 15 / 155)
 * Difficulty: Medium
 * Level: Level 1
 * Pattern: Stack / Design (Augmented Stack)
 * Why/Skill: O(1) minimum retrieval using helper stack / pair tracking
 * 
 * Complexity:
 * - Time Complexity: O(1) for push, pop, top, and getMin.
 * - Space Complexity: O(N) auxiliary space to store minimum history.
 */

class MinStack {
private:
    stack<int> s;
    stack<int> minimum;

public:
    MinStack() {}

    void push(int val) {
        s.push(val);
        // Push to minimum stack if empty or if val is <= current minimum
        if (minimum.empty() || val <= minimum.top()) {
            minimum.push(val);
        } else {
            minimum.push(minimum.top());
        }
    }

    void pop() {
        s.pop();
        minimum.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minimum.top();
    }
};

int main() {
    cout << "Running No. 15: Min Stack..." << endl;
    
    // Test Case 1: Standard LeetCode Example
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(minStack.getMin() == -3);
    cout << "Test Case 1 Passed: getMin() -> -3" << endl;

    minStack.pop();
    assert(minStack.top() == 0);
    cout << "Test Case 2 Passed: top() -> 0" << endl;

    assert(minStack.getMin() == -2);
    cout << "Test Case 3 Passed: getMin() -> -2" << endl;

    // Test Case 4: Duplicate minimum elements
    MinStack minStack2;
    minStack2.push(2);
    minStack2.push(2);
    minStack2.push(3);
    assert(minStack2.getMin() == 2);
    minStack2.pop(); // pop 3
    minStack2.pop(); // pop one 2
    assert(minStack2.getMin() == 2); // remaining 2 is still minimum
    cout << "Test Case 4 Passed: Duplicate minimum handling -> 2" << endl;

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}
