class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> r_indegree(k+1, 0);
        unordered_map<int, set<int>> r_graph;
        vector<int> c_indegree(k+1, 0);
        unordered_map<int, set<int>> c_graph;

        for(int i=0;i<rowConditions.size();i++){
            if(!r_graph[rowConditions[i][0]].count(rowConditions[i][1])){
                r_indegree[rowConditions[i][1]]++;
                r_graph[rowConditions[i][0]].insert(rowConditions[i][1]);
            }
            
        }
        for(int i=0;i<colConditions.size();i++){
            if(!c_graph[colConditions[i][0]].count(colConditions[i][1])){
                c_indegree[colConditions[i][1]]++;
                c_graph[colConditions[i][0]].insert(colConditions[i][1]);
            }
        }

        //
        queue<int> q;
        vector<int> r_loc(k+1, -1);
        int r_index=0;
        for(int i=1;i<r_indegree.size();i++){
            if(!r_indegree[i]){
                q.push(i);
                r_loc[i] = r_index++;
            }
        }

        if(q.empty()){
            return vector<vector<int>>();
        }
        //cout<<q.size()<<endl;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adj_nodes: r_graph[node]){
                r_indegree[adj_nodes]--;
                if(!r_indegree[adj_nodes]){
                    q.push(adj_nodes);
                    r_loc[adj_nodes] = r_index++;
                }
            }
        }
        
        for(int i=1;i<=k;i++){
            //cout<<r_index<<endl;
            if(r_loc[i]==-1 && r_indegree[i]==0) r_loc[i] = r_index++;
            else if(r_loc[i]==-1) return vector<vector<int>>();
        }
        
        //
        q = queue<int>();
        vector<int> c_loc(k+1, -1);
        int c_index=0;
        for(int i=1;i<c_indegree.size();i++){
            if(!c_indegree[i]){
                q.push(i);
                c_loc[i] = c_index++;
            }
        }

        if(q.empty()){
            return vector<vector<int>>();
        }
    

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adj_nodes: c_graph[node]){
                c_indegree[adj_nodes]--;
                if(!c_indegree[adj_nodes]){
                    q.push(adj_nodes);
                    c_loc[adj_nodes] = c_index++;
                }
            }
        }

        for(int i=1;i<=k;i++){
            //cout<<c_index<<endl;
            if(c_loc[i]==-1 && c_indegree[i]==0) c_loc[i] = c_index++;
            else if(c_loc[i]==-1) return vector<vector<int>>();
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        //return res;
        for(int i=1;i<=k;i++){
            res[r_loc[i]][c_loc[i]] = i;
        }

        return res;
    }
};