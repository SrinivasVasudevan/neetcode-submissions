class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj_stations;
        vector<string> res;

        for(auto ticket: tickets){
            adj_stations[ticket[0]].push_back(ticket[1]);
        }

        for(auto [k,v]: adj_stations){
            sort(v.begin(), v.end());
            adj_stations[k] = v;
        }

        unordered_map<string, vector<bool>> visited_stations;
        for(auto [k,v]: adj_stations){
            visited_stations[k] = vector<bool>(v.size(), false);
        }

        auto dfs = [&](this auto&& self, string station) -> bool {
            if(res.size() == tickets.size() + 1){
                return true;
            }
            if(!adj_stations.count(station)) return false;

            for(int i=0;i<adj_stations[station].size();i++){
                if(visited_stations[station][i]) continue;
                res.push_back(adj_stations[station][i]);
                visited_stations[station][i] = true;
                if(self(adj_stations[station][i])) return true;
                visited_stations[station][i] = false;
                res.pop_back();
            }

            return false;
        };
        res.push_back("JFK");
        dfs("JFK");
        return res;
        
    }
};
