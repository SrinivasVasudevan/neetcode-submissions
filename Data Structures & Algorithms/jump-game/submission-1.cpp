class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for(int index = 0; index < nums.size() ; index++){
            int reach = index + nums[index];
            maxIndex = max(maxIndex, reach);
        
            if(maxIndex >= nums.size()-1) return true;
            if(maxIndex == index) return false;
        }
        return false;
    }
};
