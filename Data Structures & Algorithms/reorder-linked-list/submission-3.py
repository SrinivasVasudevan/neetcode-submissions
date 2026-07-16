# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        curr = head
        
        if not curr or not curr.next: return None

        while curr and curr.next:
            nxt = curr.next
            prev = curr
            final = curr
            while final.next:
                prev = final
                final = final.next

            if curr == prev:
                break
            
            curr.next = final
            prev.next = None
            final.next = nxt

            curr = curr.next.next
