class Solution:
    def isPalindrome(self, s: str) -> bool:
        st, e = 0, len(s)-1


        while st<e:
            while not s[st].isalnum():
                if st>=len(s)-1: break
                st+=1

            while not s[e].isalnum():
                if e<0: break
                e-=1

            if st>=e: break

            if s[st].lower() != s[e].lower(): return False
            
            st+=1
            e-=1

        return True
        