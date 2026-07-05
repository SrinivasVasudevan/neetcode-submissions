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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode* dummy_node = new ListNode(-1, head);
        ListNode* prev = dummy_node;
        ListNode* curr = head;
        int index = 1;
        while(curr){
            if(index == left){
                ListNode* temp = curr;
                ListNode* c = curr->next;
                ListNode* p = curr;
                while(index + 1 <= right && c){
                    ListNode* n = c->next;
                    c->next = p;
                    p = c;
                    c = n;
                    index++;
                }
                prev->next = p;
                temp->next = c;
                break;
            }
            index++;
            prev = curr;
            curr = curr->next;
        }
        return dummy_node->next;
    }
};