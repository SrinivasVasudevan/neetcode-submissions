class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1, false);
        unordered_set<string> wordSet;
        unordered_set<int> wordLenSet;
        dp[s.length()]=true;
        for(int i=0;i<wordDict.size();i++){
            wordSet.insert(wordDict[i]);
            wordLenSet.insert(wordDict[i].length());
        }

        for(int i=s.length()-1;i>=0;i--){
            for(int wL:wordLenSet){
                if(i+wL<=s.length()){
                    string temp = s.substr(i, wL);
                    if(wordSet.count(temp)){
                        dp[i]=dp[i+wL]||dp[i];
                    }
                }
            }    
        }

        return dp[0];
    }
};
