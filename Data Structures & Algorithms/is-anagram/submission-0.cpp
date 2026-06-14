class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(char& c:s){
            mp[c]+=1;
        }
        for(char& c:t){
            mp[c]-=1;
        }
        for(const auto &[key, value]: mp){
            if(value!=0) return false;
        }
        return true;
    }
};
