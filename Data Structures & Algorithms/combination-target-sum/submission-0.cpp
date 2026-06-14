class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sum;
        auto dfs = [&](this auto &&self, int i, int s) -> void{
            if(s>=target || i>=nums.size()){
                if(s==target){
                    res.push_back(sum);
                }
                return;
            }
            s+=nums[i];
            sum.push_back(nums[i]);
            self(i, s);
            s-=nums[i];
            sum.pop_back();
            self(i+1, s);
            return;
        };
        dfs(0, 0);
        return res;
    }
};
