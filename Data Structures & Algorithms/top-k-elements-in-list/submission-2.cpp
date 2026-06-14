class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> out;
        for(auto& n:nums){
            mp[n]++;
        }
        map<int,vector<int>,greater<int>> mp_out;
        for(auto& [key,v]:mp){
            mp_out[v].push_back(key);
        }
        for(auto& [key,v]:mp_out){
            out.insert(out.end(), v.begin(), v.end());
            cout<<":"<<out.size()<<" "<<key<<endl;
            if(out.size() == k) return out;
        }
        return out;
        
    }
};
