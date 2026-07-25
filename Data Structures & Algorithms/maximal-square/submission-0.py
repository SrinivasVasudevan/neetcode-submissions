class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:

        visited = set()
        m, n = len(matrix), len(matrix[0])
        dp = {}
        maxlen = 0

        def dfs(i, j):
            if i < 0 or j < 0 or i >= m or j >= n:
                return 0
            if matrix[i][j] == '0':
                return 0

            if (i,j) in dp:
                return dp[(i,j)]
            
            res = 1 + min(min(dfs(i + 1, j), dfs(i, j+1)), dfs(i+1, j+1))
            #print(res, i, j)
            dp[(i,j)] = res
            return res
        
        for i in range(m):
            for j in range(n):
                maxlen = max(maxlen, dfs(i, j))
        
        return maxlen*maxlen
        
        