class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int f=nums[nums[0]],s=nums[0];
        while(f!=s){
            f=nums[nums[f]];
            s=nums[s];
        }
        s=0;
        while(f!=s){
            f=nums[f];
            s=nums[s];
        }
        return f;
    }
};
