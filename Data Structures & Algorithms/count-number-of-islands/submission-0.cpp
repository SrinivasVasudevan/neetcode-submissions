class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        auto dfs = [&](this auto&& self, int i, int j) -> void{
            if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0'||visited[i][j]) return;
            visited[i][j]=true;
            self(i+1,j);
            self(i,j+1);
            self(i-1,j);
            self(i,j-1);
        };

        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                //cout<<r<<" "<<c<<endl;
                if(!visited[r][c] && grid[r][c]=='1'){
                    //visited[r][c]=true;
                    dfs(r,c);
                    count++;
                }
            }
        }

        return count;
    }
};
