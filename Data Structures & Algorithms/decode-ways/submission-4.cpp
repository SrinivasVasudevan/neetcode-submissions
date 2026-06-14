class Solution {
public:
    int numDecodings(string s) {
        int N = s.length();
        vector<int> dp(N+1, 0);
        int prev = s[N-1]-'0';
        if(prev != 0) dp[N-1] = 1;
        dp[N]=1;
        for(int i=N-2;i>=0;i--){
            int num = s[i]-'0';
            if(num == 0){
                prev = 0;
                continue;
            }
            if((num == 2 && prev < 7) || (num == 1)){
                dp[i] = dp[i+1] + dp[i+2];
            }else{
                dp[i] = dp[i+1];
            }
            prev=num;
        }
        return dp[0];
    }
};
