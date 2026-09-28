#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <unordered_set>

using namespace std;

/*
 * Problem: Linked List Cycle (LeetCode 141)
 * Difficulty: Easy
 * Level: Level 1
 * Pattern: Fast & Slow Pointers (Floyd's Cycle-Finding Algorithm)
 * Why/Skill: Relative-speed pointers
 * 
 * Problem Statement:
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * (Solve this on LeetCode: https://leetcode.com/problems/linked-list-cycle/)
 * 
 * Complexity:
 * - Time Complexity: O(N) linear scan through nodes.
 * - Space Complexity: O(1) constant auxiliary space.
 */

// LeetCode singly-linked list node definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Approach 1: Hash Set of Pointers - O(N) Time, O(N) Space
    bool hasCycleSet(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode *current = head;

        while (current != nullptr) {
            if (visited.count(current)) {
                cout << "Cycle exists at node " << current->val << endl;
                return true;
            }
            visited.insert(current);
            current = current->next;
        }
        cout << "No cycles exist" << endl;
        return false;
    }

    // Approach 2: Fast & Slow Pointers (Floyd's Algorithm) - O(N) Time, O(1) Space
    bool hasCycle(ListNode *head) {
        // Initialize 2 pointers slow and fast to head
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move 1 step
            fast = fast->next->next;    // Move 2 steps

            if (slow == fast) {
                // Check the exact point of cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                cout << "Cycle is at node value: " << slow->val << endl;
                return true; // Fast runner lapped slow runner -> Cycle detected!
            }
        }
        cout << "No cycles found" << endl;
        return false;
    }
};

int main() {
    cout << "Running No. 22: Linked List Cycle...\n" << endl;
    Solution solver;

    // Test Case 1: List with a Cycle [3 -> 2 -> 0 -> -4 -> (connects back to node 2)]
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // Cycle created here!

    cout << "Test 1 (Cyclic list 3 -> 2 -> 0 -> -4 -> 2):\n";
    assert(solver.hasCycle(n1) == true);
    assert(solver.hasCycleSet(n1) == true);

    // Test Case 2: List without a Cycle [1 -> 2 -> NULL]:
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << "\nTest 2 (Linear list 1 -> 2 -> NULL):\n";
    assert(solver.hasCycle(head2) == false);
    assert(solver.hasCycleSet(head2) == false);

    // Test Case 3: Empty List
    cout << "\nTest 3 (Empty list NULL):\n";
    assert(solver.hasCycle(nullptr) == false);

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}
