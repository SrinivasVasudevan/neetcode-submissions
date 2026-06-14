class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1,1);
        //dp[nums.size()]=1;
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=i;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
        }
        int maxDp = 0;
        for(int d:dp){
            maxDp=max(maxDp,d);
        }
        return maxDp;
    }
};
