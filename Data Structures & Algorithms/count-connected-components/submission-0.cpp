class Solution {
public:
    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>> adj){
        if(vis[node]) return;
        vis[node] = 1;
        for(auto adj_node: adj[node]){
            if(adj_node!=parent){
                dfs(adj_node, node, vis, adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int number_components = 0;
        vector<vector<int>> adj(n, vector<int>());
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(n, 0);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, -1,visited, adj);
                number_components++;
            }
        }

        return number_components;
    }
};
