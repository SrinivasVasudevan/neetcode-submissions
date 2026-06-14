class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto preq: prerequisites){
            int first=preq[0], second=preq[1];
            adj[first].push_back(second);
        }
        vector<int> visited(numCourses,-1);
        vector<int> solution;
        auto cycle = [&](this auto&& self, int node) -> bool {
            if(visited[node]==1) return false;
            if(visited[node]==0) return true;
            visited[node]=0;
            for(int i=0;i<adj[node].size();i++){
                if(self(adj[node][i])) return true;
            }
            visited[node]=1;
            solution.push_back(node);
            return false;
        };
        for(int i=0;i<numCourses;++i){
            if(cycle(i)) return {};
        }   
        return solution;
        
    }
};
