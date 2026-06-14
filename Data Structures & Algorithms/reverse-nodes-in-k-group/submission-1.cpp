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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pNode = dummy;
        ListNode* cNode = head;

        ListNode* tmp = dummy;
        while(cNode!=nullptr){
            int n = 0;
            while(n<k && cNode!=nullptr){
                pNode = cNode;
                cNode = cNode->next;
                n++;
            }
            if(n<k && cNode == nullptr) break;
            ListNode* tp = tmp->next;
            ListNode* c = tp;
            ListNode* p = cNode;
            while(c!=cNode){
                ListNode* n = c->next;
                c->next = p;
                p = c;
                c = n;
            }
            tmp->next = pNode;
            tmp = tp;
            pNode = tmp;
        }
        return dummy->next;
    }
};
