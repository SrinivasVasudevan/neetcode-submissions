class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = {}

        def dfs(i, j):
            if i == len(triangle):
                return 0

            if j == len(triangle[i]):
                return 2 * 10**6

            if (i,j) in dp:
                return dp[(i,j)]

            res = 2 * 10**6
            for nxt in range(2):
                nxt_j = nxt + j
                res = min(res, triangle[i][j] + dfs(i+1, nxt_j))
            
            dp[(i,j)] = res
            return res
        
        return dfs(0, 0)


                
        