class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int count=0,runningCount=0;
        auto dfs = [&](this auto &&self, int i, int j) -> void {
            if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||visited[i][j]||grid[i][j]==0) return;
            visited[i][j] = 1;
            runningCount++;
            self(i+1,j);
            self(i,j+1);
            self(i-1,j);
            self(i,j-1);
            
            return;
        };

        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(!visited[r][c]&&grid[r][c]==1){
                    dfs(r,c);
                    count=max(count, runningCount);
                    runningCount=0;
                }
            }
        }
        return count;
        
    }
};
