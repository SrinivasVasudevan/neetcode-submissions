class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> sol;
        auto compare = [](pair<vector<int>,float> a, pair<vector<int>,float> b){return a.second < b.second;};
        priority_queue<pair<vector<int>,float>, vector<pair<vector<int>,float>>, decltype(compare)> pq;
        for(auto vec: points){
            int x = vec[0];
            int y = vec[1];
            float dist = sqrt(pow(x,2)+pow(y,2));
            if(pq.size()<k){
                pq.push(make_pair(vec,dist));
            }
            else{
                float comp = pq.top().second;
                cout<<comp<<endl;
                if(comp > dist){
                    pq.pop();
                    pq.push(make_pair(vec,dist));
                }
            }
        }
        while(!pq.empty()){
            sol.push_back(pq.top().first);
            pq.pop();
        }
        return sol;
    }
};
