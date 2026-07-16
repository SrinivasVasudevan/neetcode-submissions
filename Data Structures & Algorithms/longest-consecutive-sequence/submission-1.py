class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mp = defaultdict(int)
        for num in nums:
            mp[num]+=1
        count = 0
        for num in nums:
            if num+1 in mp:
                continue
            else:
                val = num
                local_count = 0
                while val in mp:
                    local_count+=1
                    val-=1
                
                count = max(count, local_count)

        return count

        