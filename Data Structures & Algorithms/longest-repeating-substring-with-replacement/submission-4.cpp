class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l=0,count=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]+=1;
            int maxFreq = 0;
            for(auto& [k,v]: mp){
                maxFreq=max(maxFreq, v);
            }
            while((i-l+1)-maxFreq > k){
                mp[s[l]]--;
                l++;
                if(mp[s[l]]==0) mp.erase(s[l]);
            }
            count=max(count,i-l+1);
            //cout<<count<<" "<<l<<endl;
        }
        return count;
    }
};
