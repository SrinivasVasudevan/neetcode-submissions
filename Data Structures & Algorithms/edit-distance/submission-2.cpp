class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1=0, w2=0, totalChange=INT_MAX;

        map<pair<int,int>, int> dp;

        const auto dfs = [&](this auto&& self, int w1, int w2) -> int {
            if(w2 == word2.length()){
                int currChange = (word1.length() - w1);
                return currChange;
            }
            if(w1 == word1.length()) return (word2.length() - w2);
            if(dp.count({w1,w2})) return dp[{w1, w2}];
            int runChange1=INT_MAX, runChange2=INT_MAX, totalChange = 0;
            if(word1[w1] == word2[w2]){
                runChange1 = self(w1+1, w2+1);
            }else{
                runChange2 = min(self(w1,w2+1) + 1, min(self(w1+1,w2) + 1, self(w1+1,w2+1) + 1));

            }
            totalChange = min(runChange1, runChange2);    
            dp[{w1,w2}] = totalChange;   
            return totalChange;
        };

        return dfs(0, 0);
        //return totalChange;
    }
};
