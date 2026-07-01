class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int highest_lvl = grid[0][0];
        pq.push({0, {0,0}});
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<int>> directions = {
            {-1,0},
            {1,0},
            {0,1},
            {0,-1}
        };
        while(!pq.empty()){
            auto [lvl, coordinates] = pq.top();
            pq.pop();
            auto [x, y] = coordinates;
            visited[x][y] = true;
            highest_lvl = max(highest_lvl, lvl);
            if(x == grid.size() - 1 && y == grid[0].size() - 1) break;
            for(auto direction: directions){
                int newX = x+direction[0];
                int newY = y+direction[1];
                if(newX >= grid.size() || newX < 0 || newY >= grid[0].size() || newY < 0) continue;
                if(visited[newX][newY]) continue;
                pq.push({grid[newX][newY], {newX, newY}});
            }
        } 
        return highest_lvl;
    }
};
