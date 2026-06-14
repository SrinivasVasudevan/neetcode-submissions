class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int& n:nums){
            if(mp.find(n)!=mp.end()) return true;
            mp[n]=1;
        }
        return false;
    }
};