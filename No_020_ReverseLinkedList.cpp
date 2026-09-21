#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

/*
 * Problem: Reverse Linked List (LeetCode 206)
 * Difficulty: Easy
 * Level: Level 1
 * Pattern: Linked List / 3-Pointer Reversal
 * Why/Skill: Pointer manipulation
 * 
 * Problem Statement:
 * (Solve this on LeetCode: https://leetcode.com/problems/reverse-linked-list/)
 * 
 * Complexity:
 * - Time Complexity: O(N) linear single-pass scan through N nodes.
 * - Space Complexity: O(1) constant auxiliary space.
 */

// LeetCode singly-linked list node definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* back = nullptr;
        ListNode* current = head;
        ListNode* front = nullptr;

        while (current != nullptr) {
            front = current->next; // Save tomorrow (next node)
            current->next = back;  // Change direction today
            back = current;        // Move references: back = current
            current = front;       // Move references: current = front
        }

        return back; // New head of reversed list
    }
};

// Helper function to create linked list from vector (for local testing)
ListNode* createLinkedList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print linked list (for local testing)
void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    cout << "Running No. 20: Reverse Linked List..." << endl;
    Solution solver;
    
    // Test Case 1: Standard 5-element list
    ListNode* head1 = createLinkedList({1, 2, 3, 4, 5});
    cout << "Original List: ";
    printLinkedList(head1);
    ListNode* rev1 = solver.reverseList(head1);
    cout << "Reversed List: ";
    printLinkedList(rev1);

    // Test Case 2: 2-element list
    ListNode* head2 = createLinkedList({1, 2});
    ListNode* rev2 = solver.reverseList(head2);
    assert(rev2->val == 2 && rev2->next->val == 1);
    cout << "Test Case 2 Passed: [1, 2] -> [2, 1]" << endl;

    // Test Case 3: Empty list
    ListNode* head3 = createLinkedList({});
    ListNode* rev3 = solver.reverseList(head3);
    assert(rev3 == nullptr);
    cout << "Test Case 3 Passed: [] -> []" << endl;

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}
