class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> prefix_sum(nums);
        int array_size = INT_MAX;
        for(int i=1;i<prefix_sum.size();i++){
            prefix_sum[i] = prefix_sum[i] + prefix_sum[i-1];
        }

        for(int i=0;i<nums.size();i++){
            int l = i, r = nums.size()-1;
            while(l<=r){
                int mid = (l+r)/2;
                int left_sum = 0, right_sum = prefix_sum[mid];
                if(i>0){
                    left_sum = prefix_sum[i-1];
                }
                
                if((right_sum-left_sum) >= target){
                    r = mid - 1;
                    array_size = min(array_size, mid - i + 1);
                }else{
                    l = mid + 1;
                }
            }
        }

        return array_size == INT_MAX ? 0 : array_size;
    }
};