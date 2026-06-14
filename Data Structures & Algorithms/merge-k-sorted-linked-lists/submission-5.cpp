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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val <= list2->val){
                dummy->next=list1;
                list1=list1->next;
                dummy=dummy->next;
            }else{
                dummy->next=list2;
                list2=list2->next;
                dummy = dummy->next;
            }
        }
        if(list1!=nullptr){
            dummy->next=list1;
        }
        if(list2!=nullptr){
            dummy->next=list2;
        }
        return curr->next;
    }
    void itCheck(ListNode* t){
        while(t!=nullptr){
            cout<<t->val<<" ";
            t=t->next;
        }
        cout<<endl;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i=0;
        //cout<<lists.size()<<endl;
        while(lists.size()>1){
            vector<ListNode*> tmp;
            while(i<lists.size()){
                if(i + 1 < lists.size()){
                    ListNode* t = merge(lists[i],lists[i+1]);
                    tmp.push_back(t);
                } else {
                    tmp.push_back(lists[i]);
                }
                i+=2;
            }
            lists=tmp;
            i=0;
        }
        if(lists.size() == 1) return lists[0];
        else return nullptr;
    }
};
