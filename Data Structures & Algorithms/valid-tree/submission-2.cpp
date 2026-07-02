class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        //vector<bool> inpath_visited(n, false);

        auto dfs = [&](this auto&& self, int parent, int node) -> bool {
            if(visited[node]) return false;
            visited[node] = true;
            for(auto adj_node: adj[node]){
                if(adj_node!=parent){
                    if(!self(node, adj_node)) return false;
                }
            }
            return true;
        };

        if(!dfs(-1, 0)) return false;
        for(int i=0;i<visited.size();i++){
            if(visited[i]==false) return false;
        }
        return true;
    }
};
