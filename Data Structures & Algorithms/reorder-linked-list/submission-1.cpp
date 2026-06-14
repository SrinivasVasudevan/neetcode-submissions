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
    void reorderList(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;
        if(head->next == nullptr) return;
        while(f!=nullptr && f->next!=nullptr){
            s=s->next;
            f=f->next->next;
        }
        ListNode* curr=s->next;
        s->next=nullptr;
        if(curr->next!=nullptr){
            ListNode* nxt=curr->next;
            curr->next=nullptr;
            while(nxt!=nullptr){
                ListNode* tmp=nxt->next;
                nxt->next=curr;
                curr=nxt;
                nxt=tmp;
            }
        }

        ListNode* i=head;
        ListNode* j=curr;
        while(i!=nullptr && j!=nullptr){
            ListNode* tmp1=i->next;
            ListNode* tmp2=j->next;
            i->next=j;
            j->next=tmp1;
            i=tmp1;
            j=tmp2;
        }
        //return head;
    }
};
