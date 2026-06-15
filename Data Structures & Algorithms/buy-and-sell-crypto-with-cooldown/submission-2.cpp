class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        //vector<int> dp(N, 0);
        vector<vector<int>> dp(N, vector<int>(2, 0));
        auto dfs = [&](this auto self, int i, bool buy) -> int {
            if(i>N-1){
                return 0;
            }
            if(dp[i][buy]) return dp[i][buy];
            if(buy){
                int b = self(i+1, !buy) - prices[i];
                int c = self(i+1, buy);
                dp[i][buy] = max(b, c);
            }else{
                int s = self(i+2, !buy) + prices[i];
                int c = self(i+1, buy);
                dp[i][buy] = max(s, c);
            }
            return dp[i][buy];
        };
        return dfs(0, true);
    }
};
