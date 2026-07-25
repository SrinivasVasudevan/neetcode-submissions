class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        dp = {}
        stoneSum = sum(stones)
        target = stoneSum//2
        print(stoneSum)
        def dfs(i, total):
            if total >= target or i == len(stones):
                print(stoneSum - total)
                return abs(total - (stoneSum - total))
            
            if (i, total) in dp:
                return dp[i, total]

            dp[(i, total)] = min(dfs(i+1, total+stones[i]), dfs(i+1, total))

            return dp[(i, total)]
        
        return dfs(0, 0)