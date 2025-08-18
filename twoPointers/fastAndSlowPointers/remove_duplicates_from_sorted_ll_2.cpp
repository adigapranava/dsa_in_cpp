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
        ListNode dummy = ListNode(0, head);
        ListNode* current = head;
        ListNode* prev = &dummy;

        while (current)
        {
            int c = 0;
            ListNode* t = current;
            while (current && prev->next->val == current->val) {
                t = current;
                current = current->next;
                c +=1;
            }
            if (c != 1){
                prev->next = current;
            }else{
                prev = t;
            }
        }
        prev->next = nullptr;
        return dummy.next;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(3);

    ListNode* result = sol.deleteDuplicates(head);

    // Print the modified linked list
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}