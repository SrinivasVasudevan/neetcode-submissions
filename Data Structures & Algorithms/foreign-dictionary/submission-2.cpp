class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for(auto word: words){
            for(auto c: word){
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }

        for(int i=0;i<words.size()-1;i++){
            string w1 = words[i], w2 = words[i+1];
            int minVal = min(w1.size(), w2.size());
            if(w1.size() > w2.size() && w1.substr(0, minVal) == w2.substr(0, minVal)) return "";
            for(int j=0;j<minVal;j++){
                if(w1[j] == w2[j]) continue;
                if(!adj[w1[j]].count(w2[j])){
                    adj[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                
                break;
            }
        }

        string res="";
        queue<char> q;

        for(auto [k, v]: indegree){
            if(v == 0){
                q.push(k);
            }
        }

        while(!q.empty()){
            char node = q.front();
            res+=node;
            q.pop();
            for(auto adj_node: adj[node]){
                indegree[adj_node]--;
                if(indegree[adj_node]==0){
                    q.push(adj_node);
                }
            }
        }
        return res.size() == indegree.size() ? res: "";
    }
};
