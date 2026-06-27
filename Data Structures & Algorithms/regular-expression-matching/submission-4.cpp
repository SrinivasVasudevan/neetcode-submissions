class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, -1));

        auto dfs = [&](this auto&& self, int i, int j) -> bool {
            if(i==s.length()){
                bool match = false;
                while(j+1<p.length()){
                    if(p[j+1]=='*'){
                        j+=2;
                    }else{
                        return false;
                    }
                }
                return j==p.length();
            }
            if(j==p.length()){
                return false;
            }
            if(dp[i][j]!=-1) return dp[i][j]; 
            if(s[i] == p[j] || p[j] == '.'){
                if(j+1<p.length() && p[j+1]=='*'){
                    dp[i][j] = self(i+1, j) || self(i+1, j+2) || self(i, j+2);
                }else{
                    dp[i][j] = self(i+1, j+1);
                }
                return dp[i][j];
            }else if(j+1 < p.length() && p[j+1] == '*'){
                dp[i][j] = self(i, j+2);
                return dp[i][j];
            }

            

            return false;

        };

        return dfs(0, 0);
        
    }
};
