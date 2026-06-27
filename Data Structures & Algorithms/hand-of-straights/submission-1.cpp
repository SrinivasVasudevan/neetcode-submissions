class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for(int h:hand){
            mp[h]+=1;
        }
        while(mp.size()){
            int g=groupSize;
            int prevK = -1;
            for(auto [k,v]: mp){
                if(g==0) break;
                if(prevK==-1){
                    mp[k]--;
                    prevK=k;
                    g--;
                }else{
                    if(prevK+1 != k) return false;
                    mp[k]--;
                    prevK=k;
                    g--;
                }
                if(mp[k] == 0) mp.erase(k);
            }
            if(g!=0) return false;
        }
        return true;

    }
};
