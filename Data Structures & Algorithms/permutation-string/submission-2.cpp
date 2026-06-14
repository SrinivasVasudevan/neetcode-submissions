class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        for(char& c:s1){
            mp[c]+=1;
        }
        int l=0,r=0;
        unordered_map<char,int> tmp;
        while(r<s2.length()){
            tmp[s2[r]]++;
            if(tmp[s2[r]]<=mp[s2[r]]){
                if(r-l+1 == s1.length()) return true;
                r++;
            }else if(mp[s2[r]]>0 && tmp[s2[r]]>mp[s2[r]]){
                while(mp[s2[r]]>0 && tmp[s2[r]]>mp[s2[r]] && l<=r){
                    tmp[s2[l]]--;
                    l++;
                }
                r++;
            }else{
                l=r+1;
                r++;
                tmp.clear();
            }
            cout<<l<<" "<<r<<endl;
        }
        return false;
    }
};
