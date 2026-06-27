class Solution {
public:
    vector<int> partitionLabels(string s) {
        int maxSoFar = -1;
        vector<int> sol;
        unordered_map<char, int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
        for(int i=0;i<s.length();i++){
            //cout<<maxSoFar<<endl;
            if(i > maxSoFar && maxSoFar != -1){
                sol.push_back(maxSoFar);
            }
            maxSoFar = max(maxSoFar, mp[s[i]]);
        }
        sol.push_back(maxSoFar);
        for(int i=sol.size()-1;i>=1;i--){
            sol[i] = sol[i] - sol[i-1];
        }
        sol[0] = sol[0] + 1;
        return sol;
    }
};
