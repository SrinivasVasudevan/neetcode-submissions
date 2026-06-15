class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0]=1;
        for(int n:nums){
            unordered_map<int, int> nextDp;
            for(auto [k,v]: dp){
                nextDp[k+n]+=v;
                nextDp[k-n]+=v;
            }
            dp = nextDp;
        }
        return dp[target];
    }
    
};
