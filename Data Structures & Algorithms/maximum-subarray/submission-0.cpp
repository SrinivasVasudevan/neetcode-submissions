class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], runningSum = nums[0];
        for(int i=1;i<nums.size();i++){
            
            if(runningSum < 0) runningSum = nums[i];
            else runningSum+=nums[i];
            maxSum = max(maxSum, runningSum);
        }
        
        return maxSum;
    }
};
