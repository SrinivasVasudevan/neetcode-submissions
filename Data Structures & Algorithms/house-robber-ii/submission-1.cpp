class Solution {
public:
    int houseRobber(vector<int> houses){
        int rob1=0, rob2=0;
        for(auto h:houses){
            int temp=rob2;
            rob2=max(h+rob1, rob2);
            rob1=temp;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        return max(houseRobber(vector<int>(nums.begin()+1,nums.end())),houseRobber(vector<int>(nums.begin(),nums.end()-1)));
    }
};
