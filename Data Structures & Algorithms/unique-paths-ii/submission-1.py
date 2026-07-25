class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0] == 1:
            return 0

        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = {}
      
        
        def dfs(i, j):
            
            if i < 0 or j < 0 or i >= m or j >= n or obstacleGrid[i][j] == 1:
                return 0
            if i == m-1 and j == n-1:
                return 1
            
            if (i,j) in dp:
                return dp[(i,j)]
            
            dp[(i,j)] = dfs(i+1, j) + dfs(i, j+1)
            
            return dp[(i,j)]
        
        return dfs(0,0)


        