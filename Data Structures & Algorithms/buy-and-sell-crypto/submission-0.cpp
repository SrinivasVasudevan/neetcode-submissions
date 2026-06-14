class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar=INT_MAX;
        int out=0;
        for(int& p:prices){
            out=max(out,p-minSoFar);
            minSoFar=min(minSoFar,p);
        }
        return out;
    }
};
