class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        //int res = 0;
        pq.push({grid[0][0], {0,0}});
        vector<vector<int>> directions = {
            //{-1, 0},
            {1, 0},
            //{0, -1},
            {0, 1}
        };
        while(!pq.empty()){
            auto [cost, coord] = pq.top();
            pq.pop();
            
            auto [x, y] = coord;
            visited[x][y] = 1;

            if(x==grid.size()-1 && y==grid[0].size()-1){
                return cost;
            }

            for(auto direction: directions){
                int newX = x + direction[0];
                int newY = y + direction[1];
                if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size() || visited[newX][newY]) continue;
                pq.push({(cost+grid[newX][newY]), {newX, newY}});
            }
        }
        return -1;
    }
};