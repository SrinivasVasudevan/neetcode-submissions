class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] <= 0){
                nums[i] = n+1;
            }
        }
        for(int i=0;i<n;i++){
            if(abs(nums[i]) <= n){
                int index = abs(nums[i])-1;
                //cout<<index<<endl;
                nums[index] = -1*abs(nums[index]);
            }
        }
        
        for(int i=1;i<=n;i++){
            //cout<<nums[i-1]<<endl;
            if(nums[i-1] >= 0){
                return i;
            }
        }
        return n+1;
    }
};