class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> sol(3,-1);
        for(int i=0;i<triplets.size();i++){
            auto triplet = triplets[i];
            if(triplet[0] > target[0] || 
            triplet[1] > target[1] ||
            triplet[2] > target[2])
            {
                continue;
            }else{
                if(triplet[0] == target[0]){
                    sol[0] = target[0];
                }
                if(triplet[1] == target[1]){
                    sol[1] = target[1];
                }
                if(triplet[2] == target[2]){
                    sol[2] = target[2];
                }
            }   
        }
        for(int s:sol){
            if(s==-1) return false;
        }
        return true;
    }
};
