class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = [[0] * (len(triangle[-1])+1) for _ in range(len(triangle)+1)]

        for i in range(len(triangle)+1):
            dp[i][len(triangle[-1])] = float('inf')

        for j in range(len(triangle[-1])+1):
            dp[len(triangle)][j] = 0

        for i in range(len(triangle)-1, -1, -1):
            for j in range(len(triangle[-1])-1, -1, -1):
                if j < len(triangle[i]):
                    dp[i][j] = min(dp[i+1][j] + triangle[i][j], dp[i+1][j+1] + triangle[i][j])

        return dp[0][0]
        


                
        