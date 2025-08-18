#include<iostream>
#include<vector>
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* i = head;
        ListNode* j = head;

        while(j != nullptr){
            if (i->val != j->val)
            {
                i->next = j;
                i = j;
            }
            
            j = j->next;
        }

        if (i!=j)
        {
            i->next=nullptr;
        }
        
        return head;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    // head->next->next->next->next->next = new ListNode(4);

    ListNode* result = sol.deleteDuplicates(head);

    // Print the modified linked list
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}