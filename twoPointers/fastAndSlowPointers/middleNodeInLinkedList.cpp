#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int c = 0;
        ListNode* t = head;
        while (t)
        {
            c++;
            t = t->next;
        }

        t = head;
        int reqd = ceil(c/2), i = 0;
        while(i < reqd){
            i++;
            t = t->next;
        }
        return t;
    }

    ListNode* middleNode2(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // move fast by 2 and slow by 1
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // when fast reaches end, slow is at middle
        return slow;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = sol.middleNode2(head);

    // Print the middle node value
    cout << "Middle Node Value: " << result->val << endl;

    return 0;
}