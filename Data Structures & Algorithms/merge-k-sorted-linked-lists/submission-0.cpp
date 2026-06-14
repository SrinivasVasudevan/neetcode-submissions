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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists[0];
        head->next = lists[0];
        ListNode* p = head;
        ListNode* l = p->next;
        int other = 1;
        ListNode* o = nullptr;

        while(other < lists.size()){
            o = lists[other];
            p = head;
            l = p->next;
            while(l!=nullptr && o!=nullptr){
                if(l->val <= o->val){
                    p=l;
                    l=l->next;
                }else{
                    p->next=o;
                    o=o->next;
                    p->next->next=l;
                    p=p->next;
                }
            }
            while(o!=nullptr){
                p->next=o;
                o=o->next;
                p->next->next=l;
                p=p->next;
            }
            other++;
        }
        return head->next;
    }
};
