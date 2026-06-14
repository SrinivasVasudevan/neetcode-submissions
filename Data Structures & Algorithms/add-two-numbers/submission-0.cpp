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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode();
        ListNode* run=head;
        int rem=0;
        while(l1!=nullptr && l2!=nullptr){
            ListNode* newnode = new ListNode();
            int num=(l1->val+l2->val+rem);
            rem=num/10;
            num=num%10;
            newnode->val=num;
            run->next=newnode;
            run=newnode;
            l1=l1->next;
            l2=l2->next;
        }
        if(rem!=0 || l1!=nullptr || l2!=nullptr){
            while(l1!=nullptr){
                ListNode* newnode = new ListNode();
                int num=(l1->val+rem);
                rem=num/10;
                num=num%10;
                newnode->val=num;
                run->next=newnode;
                run=newnode;
                l1=l1->next;
            }
            while(l2!=nullptr){
                ListNode* newnode = new ListNode();
                int num=(l2->val+rem);
                rem=num/10;
                num=num%10;
                newnode->val=num;
                run->next=newnode;
                run=newnode;
                l2=l2->next;
            }
            if(rem!=0){
                ListNode* newnode = new ListNode();
                int num=(rem);
                rem=num/10;
                num=num%10;
                newnode->val=num;
                run->next=newnode;
                run=newnode;
            }
        }
        return head->next;
    }
};
