class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,out=0;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])!=mp.end()){
                start=max(start,mp[s[i]]+1);
            }
            cout<<start<<endl;
            mp[s[i]]=i;
            out=max(out,i-start+1);
        }
        return out;
    }
};
