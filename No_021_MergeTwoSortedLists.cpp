#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

/*
 * Problem: Merge Two Sorted Lists (LeetCode 21)
 * Difficulty: Easy
 * Level: Level 1
 * Pattern: Linked List / Merge Splicing
 * Why/Skill: Merge with pointers
 * 
 * Problem Statement:
 * (Solve this on LeetCode: https://leetcode.com/problems/merge-two-sorted-lists/)
 * 
 * Complexity:
 * - Time Complexity: O(N + M) where N and M are the lengths of the two lists.
 * - Space Complexity: O(1) iterative in-place pointer manipulation.
 * 
 * Key Note:
 * In list you don't need to iterate till end, if one reaches nullptr just attach the other one at the current end.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // In list you don't need to iterate till end, if one reaches null ptr just attach the other one at the current end
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return dummy.next;
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

// Helper function to convert linked list to vector (for local testing assertions)
vector<int> linkedListToVector(ListNode* head) {
    vector<int> result;
    ListNode* curr = head;
    while (curr != nullptr) {
        result.push_back(curr->val);
        curr = curr->next;
    }
    return result;
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
    cout << "Running No. 21: Merge Two Sorted Lists..." << endl;
    Solution solver;

    // Test Case 1: Standard example
    ListNode* l1 = createLinkedList({1, 2, 4});
    ListNode* l2 = createLinkedList({1, 3, 4});
    cout << "List 1: "; printLinkedList(l1);
    cout << "List 2: "; printLinkedList(l2);
    ListNode* merged1 = solver.mergeTwoLists(l1, l2);
    cout << "Merged List: "; printLinkedList(merged1);
    assert(linkedListToVector(merged1) == vector<int>({1, 1, 2, 3, 4, 4}));
    cout << "Test Case 1 Passed!" << endl << endl;

    // Test Case 2: Empty lists
    ListNode* l3 = createLinkedList({});
    ListNode* l4 = createLinkedList({});
    ListNode* merged2 = solver.mergeTwoLists(l3, l4);
    assert(linkedListToVector(merged2) == vector<int>({}));
    cout << "Test Case 2 Passed: [] + [] -> []" << endl;

    // Test Case 3: One empty list
    ListNode* l5 = createLinkedList({});
    ListNode* l6 = createLinkedList({0});
    ListNode* merged3 = solver.mergeTwoLists(l5, l6);
    assert(linkedListToVector(merged3) == vector<int>({0}));
    cout << "Test Case 3 Passed: [] + [0] -> [0]" << endl;

    cout << "\nAll test cases passed successfully!" << endl;
    return 0;
}
