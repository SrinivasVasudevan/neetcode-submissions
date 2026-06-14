class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        sort(nums.begin(),nums.end());
        int i=0,j=0,k=0;
        while(i<nums.size()){
            int j=i+1,k=nums.size()-1;
            int runningSum=0;
            while(j<k){
                runningSum=nums[i]+nums[j]+nums[k];
                if(runningSum==0){
                    out.push_back({nums[i],nums[j],nums[k]});
                }
                
                if(runningSum==0 || runningSum>0){
                    k--;
                    while(nums[k]==nums[k+1]) k--;
                }
                if(runningSum==0 || runningSum<0){
                    j++;
                    while(nums[j]==nums[j-1]) j++;
                }
            }
            i++;
            while(nums[i]==nums[i-1]) i++;
        }
        return out;
    }
};
