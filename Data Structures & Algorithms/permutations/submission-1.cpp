class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(), 0);
        vector<int> temp;
        temp.reserve(nums.size());
        vector<vector<int>> res;

        auto dfs = [&](this auto&& self) -> void {
            if(temp.size() == nums.size()){
                res.push_back(temp);
            }
            for(int i=0;i<nums.size();i++){
                if(visited[i]) continue;
                visited[i] = 1;
                temp.push_back(nums[i]);
                self();
                temp.pop_back();
                visited[i]=0;
            }
        };

        for(int i=0;i<nums.size();i++){
            visited[i] = 1;
            temp.push_back(nums[i]);
            dfs();
            temp.pop_back();
            visited[i]=0;
        }

        return res;
    }
};
