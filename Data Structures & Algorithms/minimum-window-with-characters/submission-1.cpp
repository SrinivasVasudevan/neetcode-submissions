class Solution {
public:
    string minWindow(string t, string s) {
        int minLen=INT_MAX;
        string out="";
        int l=0,r=0;
        int count=0;
        unordered_map<char,int> smp;
        for(char& c:s){
            smp[c]+=1;
        }

        unordered_map<char,int> tmp;
        while(r<t.length()){
            if(smp.find(t[r])!=smp.end()){
                tmp[t[r]]++;
                if(tmp[t[r]]<=smp[t[r]]) count++;
                if(count == s.length()){
                    if(minLen > r-l+1){
                        minLen = r-l+1;
                        out=t.substr(l,minLen);
                    }
                    tmp[t[l]]--;
                    if(tmp[t[l]]<smp[t[l]]) count--;
                    l++;
                    while(l<=r && tmp[t[l]] >= smp[t[l]]){
                        if(count == s.length()){
                            if(minLen > r-l+1){
                                minLen = r-l+1;
                                out=t.substr(l,minLen);
                            }
                        }
                        if(tmp[t[l]] == smp[t[l]]) break;
                        tmp[t[l]]--;
                        if(tmp[t[l]]<smp[t[l]]) count--;
                        l++;
                    }
                }
                r++;
            }else if(count > 0){
                tmp[t[r]]++;
                r++;
            }else{
                r++;
                l=r;
            }
        }
        return out;
    }

};
