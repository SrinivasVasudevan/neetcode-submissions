class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sum;
        sort(candidates.begin(), candidates.end());
        auto dfs = [&](this auto&& self, int i, int s) -> void {
            if(i>=candidates.size() || s>=target){
                if(s==target){
                    res.push_back(sum);
                }
                return;
            }
            s+=candidates[i];
            sum.push_back(candidates[i]);
            self(i+1, s);
            sum.pop_back();
            s-=candidates[i];
            while(candidates[i+1]==candidates[i]) i++;
            self(i+1, s);
            return;
        };
        dfs(0, 0);
        return res;
    }
};
