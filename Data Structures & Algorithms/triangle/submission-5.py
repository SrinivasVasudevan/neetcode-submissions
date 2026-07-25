class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = [0] * (len(triangle[-1])+1)

        # for i in range(len(triangle)+1):
        #     dp[i][len(triangle[-1])] = float('inf')

        for j in range(len(triangle[-1])+1):
            dp[j] = 0

        for i in range(len(triangle)-1, -1, -1):
            for j in range(len(triangle[i])):
                    dp[j] = min(dp[j] + triangle[i][j], dp[j+1] + triangle[i][j])

        return dp[0]
        


                
        