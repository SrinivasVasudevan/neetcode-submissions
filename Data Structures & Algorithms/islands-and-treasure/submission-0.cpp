class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        auto dfs = [&](this auto&& self, int i, int j, int dist) -> void {
            if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1 || grid[i][j] < dist) return;

            grid[i][j] = min(grid[i][j], dist);
            self(i+1,j,dist+1);
            self(i,j+1,dist+1);
            self(i-1,j,dist+1);
            self(i,j-1,dist+1);
        };
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    dfs(i,j,0);
                }
            }
        }
        
    }
};
