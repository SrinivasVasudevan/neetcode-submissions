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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        if(curr == nullptr || curr->next == nullptr) return curr;
        ListNode* nxt = curr->next;
        ListNode* tmp = nullptr;
        curr->next=nullptr;
        while(nxt!=nullptr){
            
            tmp=nxt->next;
            nxt->next=curr;
            curr=nxt;
            nxt=tmp;
      
        }
        return curr;
    }
};
