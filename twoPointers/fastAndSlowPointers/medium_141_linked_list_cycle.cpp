#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        ListNode * slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

int main() {
    // Example usage:
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(0);
    // head->next->next->next = new ListNode(-4);
    // head->next->next->next->next = head->next; // Creates a cycle

    Solution solution;
    bool result = solution.hasCycle(head);
    cout << (result ? "Cycle detected" : "No cycle detected") << endl;

    // Clean up memory (not necessary in this example, but good practice)
    // delete head->next->next->next; // -4
    // delete head->next->next;        // 0
    delete head->next;              // 2
    delete head;                    // 3

    return 0;
}