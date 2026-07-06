class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n < k) return vector<vector<int>>();
        vector<vector<int>> res;
        auto dfs = [&](this auto&& self, vector<int> perm, int i, int count) -> void {
            if(i == n+1){
                if(count == k){
                    res.push_back(perm);
                }
                return;
            }
            if(count == k){
                res.push_back(perm);
                return;
            }
            perm.push_back(i);
            self(perm, i+1, count+1);
            perm.pop_back();
            self(perm, i+1, count);
        };
        dfs(vector<int>(), 1, 0);
        return res;
    }
};