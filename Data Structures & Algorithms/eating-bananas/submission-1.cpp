class Solution {
public:
    bool check(vector<int>& piles, int h, int k){
        int totalTime=0;
        for(int i=0;i<piles.size();i++){
            totalTime+=(int)ceil((double)piles[i]/(double)k);
            if(totalTime>h) return false;
        }
        
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxK=0;
        for(int i=0;i<piles.size();i++){
            maxK=max(maxK,piles[i]);
        }
        int l=1,r=maxK;
        int out=0;
        while(l<=r){
            cout<<l<<" "<<r<<endl;
            int m=(l+r)/2;
            if(check(piles, h, m)){
                out=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return out;
    }
};
