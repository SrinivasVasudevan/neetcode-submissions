class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0, freshFruitCount=0;
        std::queue<pair<int,int>> bfs;
        vector<vector<bool>> gridVisited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    bfs.push(make_pair(i,j));
                }
                else if(grid[i][j]==1){
                    freshFruitCount++;
                }
            }
        }

        int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(bfs.size()){
            int bfsCount=bfs.size();
            bool infl=false;
            while(bfsCount--){
                auto [r,c] = bfs.front();
                gridVisited[r][c]=true;
                bfs.pop();
                
                for(auto [x,y]:directions){
                    int newr = r+x, newc = c+y;
                    pair<int,int> rot=make_pair(newr,newc);
                    if(newr<0||newr>=grid.size()||newc<0||newc>=grid[0].size()||gridVisited[newr][newc]||grid[newr][newc]!=1) continue;
                    bfs.push(rot);
                    grid[newr][newc]=2;
                    infl=true;
                    freshFruitCount--;
                }
            }
            //cout<<r<<" "<<c<<endl;
            if(infl)time++;
        }
        cout<<time<<" "<<freshFruitCount<<endl;
        return freshFruitCount==0?time:-1;
    }
};
