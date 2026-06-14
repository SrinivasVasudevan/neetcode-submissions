class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0) return 0;
        vector<int> dp(amount+1, INT_MAX);
        for(int c: coins){
            if(c<=amount) dp[c]=1;
        }
        dp[0]=1;
        //reverse(coins.begin(), coins.end());
        for(int i=1;i<=amount;i++){
            if(dp[i]==INT_MAX){
                for(int c:coins){
                    if(c>i) continue;
                    int change = i-c;
                    if(dp[change] != INT_MAX){
                        dp[i] = min(dp[i], dp[change]+1);                        
                    }
                }
            } 
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
