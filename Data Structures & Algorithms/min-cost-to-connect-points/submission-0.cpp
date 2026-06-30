class Solution {
public:
    int find_parent(int node, vector<int> &parent){
        if(parent[node] == node) return node;
        parent[node] = find_parent(parent[node], parent);
        return parent[node];
    }

    void rank_union(int node1, int node2, vector<int> &parent, vector<int> &rank){
        if(rank[node1] == rank[node2]){
            parent[node2] = node1;
            rank[node1]++;
        }else if(rank[node1] > rank[node2]){
            parent[node2] = node1;
        }else{
            parent[node1] = node2;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        //unordered_map<int, vector<pair<int,int>>> graph; // they only store indices remember
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i == j) continue;
                pq.push({(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])), {i,j}});
            }
        }

        vector<int> parent(points.size());
        vector<int> rank(points.size(), 1);

        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }

        int res = 0;
        while(!pq.empty()){
            auto [distance, point_pair] = pq.top();
            pq.pop();
            auto [i,j] = point_pair;
            int node1_parent = find_parent(i, parent);
            int node2_parent = find_parent(j, parent);
            if(node1_parent!=node2_parent){
                rank_union(node1_parent, node2_parent, parent, rank);
                res+=distance;
            }
        }

        return res;
        


    }
};
