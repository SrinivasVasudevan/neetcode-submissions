#include <cstring>

int reachableP[1000][1000];
int reachableA[1000][1000];
int visited[1000][1000];


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        std::memset(reachableP, 0, sizeof(reachableP));
        std::memset(reachableA, 0, sizeof(reachableA));
        std::memset(visited, 0, sizeof(visited));
        vector<vector<int>> sol;
        auto dfs = [&](this auto self, int r, int c, int (&arr)[1000][1000], int val) -> void {
            if(r<0 || r>heights.size()-1 || c<0|| c>heights[0].size()-1) return;
            
            visited[r][c]=1;
            arr[r][c]=1;

            if(r+1 <= heights.size()-1 && heights[r+1][c]>=val && !visited[r+1][c]){
                self(r+1,c,arr,heights[r+1][c]);
            }
            if(r-1 >= 0 && heights[r-1][c]>=val && !visited[r-1][c]){
                self(r-1,c,arr,heights[r-1][c]);
            }
            if(c+1 <= heights[0].size()-1 && heights[r][c+1]>=val && !visited[r][c+1]){
                self(r,c+1,arr,heights[r][c+1]);
            }
            if(c-1 >= 0 && heights[r][c-1]>=val && !visited[r][c-1]){
                self(r,c-1,arr,heights[r][c-1]);
            }


        };
        memset(visited, 0, sizeof visited);
        for(int c=0;c<heights[0].size();c++){
            dfs(0, c, reachableP, heights[0][c]);
        }
        for(int r=0;r<heights.size();r++){
            //memset(visited, 0, sizeof visited);
            dfs(r, 0, reachableP, heights[r][0]);
        }
        memset(visited, 0, sizeof visited);
        for(int c=0;c<heights[0].size();c++){
            
            dfs(heights.size()-1, c, reachableA, heights[heights.size()-1][c]);
        }
        for(int r=0;r<heights.size();r++){
            //memset(visited, 0, sizeof visited);
            dfs(r, heights[0].size()-1, reachableA, heights[r][heights[0].size()-1]);
        }

        for(int r=0;r<heights.size();r++){
            for(int c=0;c<heights[0].size();c++){
                if(reachableP[r][c]==1 && reachableA[r][c]==1){
                    sol.push_back({r,c});
                }
            }
        }
        return sol;
    }
};
