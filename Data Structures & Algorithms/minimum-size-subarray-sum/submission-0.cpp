class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int array_size = INT_MAX, sum_so_far = 0;
        int i = -1, j = 0;
        while(i < j && j < nums.size()){
            sum_so_far += nums[j];
            
            while(sum_so_far >= target){
                array_size = min(j-i, array_size);
                i++;
                sum_so_far-=nums[i];
            }

            j++;

        }

        while(i < j && sum_so_far >= target){
            array_size = min(j-i, array_size);
            i++;
            sum_so_far-=nums[i];
        }

        return array_size == INT_MAX ? 0 : array_size;
    }
};