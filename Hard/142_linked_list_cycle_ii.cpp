/**
 * Defination for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle2(ListNode *head) {
        unordered_map<ListNode *, int> visited;
        ListNode * temp = head;
        int i =0;

        while (temp)
        {
            if (visited.find(temp) != visited.end()){
                return temp;
            }else{
                visited[temp] = i;
                i++;
                temp = temp->next;
            }
        }
        return nullptr;
    }

 ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode *slow = head, *fast = head;

        // Phase 1: Detect if cycle exists
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // cycle detected
                // Phase 2: find entry point
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // entry point of cycle
            }
        }
        return nullptr; // no cycle
    }
};

int main() {
    Solution sol;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creating a cycle

    ListNode *cycleStart = sol.detectCycle(head);
    
    if (cycleStart) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}