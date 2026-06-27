class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> padded_nums(nums.size()+2, 1);
        map<pair<int,int>, int> dp;

        for(int i=0;i<nums.size();i++){
            padded_nums[i+1] = nums[i];
        }

        auto dfs = [&](this auto&& self, int l, int r) -> int {
            if(l > r){
                return 0;
            }

            if(dp.count({l,r})) return dp[{l,r}];

            dp[{l,r}] = 0;
            
            for(int i=l;i<=r;i++){
                int coins = padded_nums[i] * padded_nums[l-1] * padded_nums[r+1] + self(l, i-1) + self(i+1, r);
                dp[{l, r}] = max(dp[{l,r}], coins);
            }

            return dp[{l,r}];

        };

        return dfs(1, nums.size());
    }
};
