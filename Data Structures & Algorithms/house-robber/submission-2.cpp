class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> sol(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            int maxVal=0;
            for(int k=i+2;k<nums.size();k++){
                maxVal=max(maxVal,sol[k]);
            }
            //cout<<maxVal<<" "<<nums[i]<<endl;
            sol[i]=nums[i]+maxVal;
            //cout<<sol[i]<<endl;
        }
        if(nums.size()>1)
        return max(sol[0],sol[1]);
        else return sol[0];
    }
};
