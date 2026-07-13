class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> adj_var;

    double seek(string val, string find, set<string>& visited){
        if(val == find){
            return 1.0;
        }

        visited.insert(val);
        double ret_val = -1.0;
        for(auto [adj_val, w]: adj_var[val]){
            if(!visited.count(adj_val)){
                ret_val = max(ret_val, w * seek(adj_val, find, visited));
            }
        }

        return ret_val;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> variables;

        vector<double> res(queries.size(), -1.0);

        for(int i=0;i<equations.size();i++){
            string num = equations[i][0], denom = equations[i][1];
            variables.insert(num);
            variables.insert(denom);

            adj_var[num].push_back({denom, values[i]});
            adj_var[denom].push_back({num, 1.0f/values[i]});
        }

        set<string> visited;

        for(int i=0;i<queries.size();i++){
            string num = queries[i][0], denom = queries[i][1];
            if(variables.count(num) && variables.count(denom)){
                double found_num = seek(num, denom, visited);
                res[i] = found_num > 0 ? found_num : -1.0;
            }
            visited = set<string>();
        }

        return res;

    }
};