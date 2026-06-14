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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* check=new ListNode();
        check->next=head;
        ListNode* run=head;
        int count=0;
        while(run!=nullptr){
            count++;
            run=run->next;
        }
        
        count=count-n;
        //cout<<count<<endl;
        ListNode* prev=check;
        ListNode* curr=head;
        //cout<<
        if(count<0) return nullptr;
        while(count--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        cout<<curr->val<<" "<<prev->val<<endl;
        delete curr;
        return check->next;
    }
};
