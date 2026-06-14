class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> sub;
        auto dfs = [&](this auto&& self, int i) -> void {
            if(i>=nums.size()){
                res.push_back(sub);
                return;
            }
            sub.push_back(nums[i]);
            self(i+1);
            sub.pop_back();
            while(i+1<nums.size()&&nums[i+1]==nums[i]) i++;
            self(i+1);
            return;
        };
        dfs(0);
        return res;
    }
};
