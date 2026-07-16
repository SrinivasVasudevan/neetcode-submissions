# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        s, f = head, head
        len = 1
        while f and s:
            if f.next:
                f = f.next.next
                len+=2
            else:
                len+=1
                break
            s = s.next
        
        target = len - n

        c = 1
        dummy = ListNode()
        dummy.next = head
        prev = dummy
        curr = head

        while c != target:
            c+=1
            prev = curr
            curr = curr.next

        nxt = curr.next
        prev.next = nxt

        return dummy.next


        