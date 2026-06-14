class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> res;
        vector<int> permutation;
        auto dfs = [&](this auto&& self) -> void {
            if(permutation.size()==nums.size()){
                res.push_back(permutation);
                return;
            }
            for(int i=0;i<nums.size();i++){
                if(used[i]) continue;
                used[i]=true;
                permutation.push_back(nums[i]);
                self();
                permutation.pop_back();
                used[i]=false;
            }
            
        };
        dfs();
        return res;
    }
};
