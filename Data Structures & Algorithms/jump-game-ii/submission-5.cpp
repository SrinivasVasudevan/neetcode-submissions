class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int maxJump = 0, maxRunJump = 0, jump = 0;
        for(int i=0;i<nums.size();i++){
            maxRunJump = max(maxRunJump, i+nums[i]);
            if(maxRunJump >= nums.size()-1) return jump+1;
            if(i == maxJump){
                maxJump = max(maxRunJump, maxJump);
                jump++;
            }
        }
        return jump;
    }
};
