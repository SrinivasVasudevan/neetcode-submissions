class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        int out=INT_MAX;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]<=nums[r]){
                out=min(out,nums[m]);
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return out;
    }
};
