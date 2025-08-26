#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newListNode = new ListNode();
        ListNode* temp = newListNode;
        int carry = 0;
        while (l1  || l2 || carry)
        {
            int l1_v = l1 ? l1->val: 0;
            int l2_v = l2 ? l2->val: 0;
            int sum = l1_v + l2_v + carry;
            carry = sum / 10;
            temp->next = new ListNode(sum%10);
            
            temp = temp->next;
            l1 = l1 ? l1->next : nullptr; 
            l2 = l2 ? l2->next : nullptr; 
        }
        return newListNode->next;
    }
};

int main(){
    Solution sol;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    while(result != nullptr){
        cout<<result->val<<" ";
        result = result->next;
    }

    return 0;
}