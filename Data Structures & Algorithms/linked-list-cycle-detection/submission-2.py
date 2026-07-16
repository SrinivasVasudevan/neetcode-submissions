# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        f, s = head, head
        while f and s:
            if f.next:
                f = f.next.next
            else:
                break
            s  = s.next
            if f == s:
                return True
        return False
        