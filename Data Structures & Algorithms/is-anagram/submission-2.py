class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        char_counter = [0]*26
        for i, char in enumerate(s):
            char_counter[ord(s[i])-ord('a')]+=1
            char_counter[ord(t[i])-ord('a')]-=1

        return not any(c != 0 for c in char_counter)
        