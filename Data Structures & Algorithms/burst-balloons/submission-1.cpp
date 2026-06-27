class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> padded_nums(nums.size()+2, 1);
        for(int i=0;i<nums.size();i++){
            padded_nums[i+1] = nums[i];
        }
        int n=nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int l=n;l>=1;l--){
            for(int r=l;r<=n;r++){
                for(int k=l;k<=r;k++){
                    int coins = padded_nums[l-1] * padded_nums[k] * padded_nums[r+1];
                    coins+= dp[l][k-1] + dp[k+1][r];
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }
        return dp[1][n];
    }
};
