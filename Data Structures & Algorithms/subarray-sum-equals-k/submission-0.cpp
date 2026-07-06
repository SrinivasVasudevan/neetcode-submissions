class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_count;
        int res = 0;
        int running_sum = 0;
        sum_count[0] = 1;
        for(int i=0;i<nums.size();i++){
            running_sum+=nums[i];
            if(sum_count.count(running_sum - k)){
                res+=sum_count[running_sum-k];
            }
            sum_count[running_sum]+=1;
        }

        return res;
    }
};