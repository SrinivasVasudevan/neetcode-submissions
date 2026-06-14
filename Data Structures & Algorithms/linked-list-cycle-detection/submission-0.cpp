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

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* a=head;
        ListNode* b=head;
        if(head==nullptr) return false;
        while(b!=nullptr && b->next!=nullptr){
            a=a->next;
            b=b->next->next;
            if(a==b) return true;
        }
        return false;
    }
};
