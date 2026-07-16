class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l, r = 0, 0
        count = defaultdict(int)
        maxF = 0
        seq = 0

        while r < len(s):
            count[s[r]]+=1
            maxF = max(maxF, count[s[r]])
            if (r - l + 1) - maxF > k:
                count[s[l]]-=1
                l+=1
            
            seq = max(seq, (r-l+1))
            r+=1


        return seq

        