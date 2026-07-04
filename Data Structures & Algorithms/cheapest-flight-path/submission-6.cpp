class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> adj_flights;
        for(auto flight: flights){
            adj_flights[flight[0]].push_back({flight[1], flight[2]});
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<int> dist;
        pq.push({0, {0, src}});
        dist[src] = 0;
        while(!pq.empty()){
            auto [cost, stop_node] = pq.top();
            auto [stop, node] = stop_node;
            pq.pop();
            if(node == dst) return cost;
            for(auto adj_flight: adj_flights[node]){
                if(stop > k) continue;
                auto [adj_node, c] = adj_flight;
                int new_cost = c+cost;
                pq.push({new_cost, {stop+1, adj_node}});
            }
        }

        return -1;
    }
};
