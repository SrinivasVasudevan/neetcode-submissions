class Solution:
    def check_match(self, truth, checker):
        for char, count in truth.items():
            if checker.get(char, 0) < count:
                return False
        
        return True

    def minWindow(self, s: str, t: str) -> str:
        count_s = {}
        count_t = {}
        l=0
        min_len = len(s)
        min_str = s

        if len(t) > len(s): return ""

        for char in t:
            count_t[char] = count_t.get(char, 0) + 1
        
        for r in range(len(s)):
            count_s[s[r]] = count_s.get(s[r], 0) + 1
            while self.check_match(count_t, count_s):
                if (r-l+1) < min_len:
                    min_len = r-l+1
                    min_str = s[l:r+1]
                count_s[s[l]]-=1
                l+=1
            
        if min_str == s:
            count_t = {}
            count_s = {}
            for char in t:
                count_t[char] = count_t.get(char, 0) + 1
            for char in s:
                count_s[char] = count_s.get(char, 0) + 1
            
            for char in t:
                if count_t.get(char, 0) > count_s.get(char, 0):
                    return ""
            
        return min_str



        