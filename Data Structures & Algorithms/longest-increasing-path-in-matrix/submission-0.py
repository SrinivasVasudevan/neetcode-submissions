class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        dp = {}
        def dfs(i: int, j: int) -> int:
            if i == len(matrix) or j == len(matrix[0]):
                return 0
            
            if (i,j) in dp: return dp[(i,j)]
            result = 0
            if i+1 < len(matrix) and matrix[i+1][j] > matrix[i][j]:
                result=max(dfs(i+1, j)+1,result)
            if i-1 >= 0 and matrix[i-1][j] > matrix[i][j]:
                result=max(dfs(i-1, j)+1,result)
            if j+1 < len(matrix[0]) and matrix[i][j+1] > matrix[i][j]:
                result=max(dfs(i, j+1)+1, result)
            if j-1 >=0  and matrix[i][j-1] > matrix[i][j]:
                result=max(dfs(i, j-1)+1, result)

            dp[(i,j)]=result
            return result

        maxPath = 0

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                res = dfs(i, j)
                print(i, j, res)
                maxPath = max(res, maxPath)

        return maxPath+1

        
            


        