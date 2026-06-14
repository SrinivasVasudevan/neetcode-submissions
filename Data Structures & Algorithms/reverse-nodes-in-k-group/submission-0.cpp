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
    ListNode* reverseKGroup(ListNode* head, int k) {
        deque<ListNode*> dq;
        ListNode* out = new ListNode();
        ListNode* h = out;
        ListNode* l = head;
        while(l!=nullptr){
            while(dq.size() < k && l!=nullptr){
                dq.push_back(l);
                l=l->next;
            }
            if(dq.size() == k){
                ListNode* curr = h;
                while(!dq.empty()){
                    curr->next = dq.back();
                    dq.pop_back();
                    curr = curr->next;
                }
                h = curr;
                h->next = l;
            }else{
                ListNode* curr = h;
                while(!dq.empty()){
                    curr->next = dq.front();
                    dq.pop_front();
                    curr = curr->next;
                }
                h = curr;
                h->next = l;
            }
        }
        return out->next;
    }
};
