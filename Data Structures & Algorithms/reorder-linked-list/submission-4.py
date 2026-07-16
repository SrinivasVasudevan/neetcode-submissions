# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        s, f = head, head
        while f and s:
            if f.next:
                f = f.next.next
            else:
                break
            
            s = s.next

        prev = None
        curr = s.next
        s.next = None
        
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        
        rev_head = prev


        curr = head
        rev_curr = rev_head
        
        while curr and rev_curr:
            nxt = curr.next
            r_nxt = rev_curr.next

            curr.next = rev_curr
            rev_curr.next = nxt

            curr = nxt
            rev_curr = r_nxt

        


