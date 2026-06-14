class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n+1, INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());
    
        for(auto time:times){
            adj[time[0]].push_back(make_pair(time[1],time[2]));
        }

        std::queue<int> q;
        q.push(k);
        distance[k]=0;
        while(q.size()){
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                int currnode = q.front();
                q.pop();
                for(int a=0;a<adj[currnode].size();a++){
                    if(distance[currnode]+adj[currnode][a].second < distance[adj[currnode][a].first]){
                        q.push(adj[currnode][a].first);
                        distance[adj[currnode][a].first] = distance[currnode]+adj[currnode][a].second;
                    }
                }
            }
        }

        int maxVal = INT_MIN;
        for(int i=1;i<=n;i++){
            maxVal=max(maxVal,distance[i]);
        }
        return maxVal==INT_MAX ? -1:maxVal;
    }
};
