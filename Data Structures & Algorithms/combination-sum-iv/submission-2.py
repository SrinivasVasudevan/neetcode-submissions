class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0]*(target+1)
        dp[0] = 1
        for i in nums:
            if i > target: continue
            dp[i] = 1
        
        for num in range(target+1):
            for i in nums:
                if i >= num:
                    continue
                #print(num, i)
                if dp[num-i]:
                    dp[num] += dp[num-i]
                #print(dp[num])
        
        return dp[target]
        