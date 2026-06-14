class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol;
        for(int i=0;i<=n;i++){
            int k=i;
            int count=0;
            while(k){
                k=k&(k-1);
                count++;
            }
            sol.push_back(count);
        }
        return sol;
    }
};
