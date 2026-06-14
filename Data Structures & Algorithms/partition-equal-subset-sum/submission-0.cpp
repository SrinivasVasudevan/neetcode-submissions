class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> part;
        part.insert(0);
        int total = 0;
        for(auto n:nums){
            total+=n;
        }
        for(auto n:nums){
            for(auto p:part){
                part.insert(p+n);
                if((float)(p+n) == total/2.0f) return true;
            }
        }
        return false;

    }
};
