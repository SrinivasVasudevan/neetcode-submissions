class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            if(mp.find(target-n)!=mp.end()){
                return {mp[target-n],i};
            }
            mp[n]=i;
        }
        return {-1,-1};
    }
};
