class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> sol;
        
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) -> bool {return a[0] < b[0];});
        sol.push_back(intervals[0]);
        // for(auto interval:intervals){
        //     cout<<interval[0]<<" "<<interval[1]<<endl;
        // }
        for(int i=1;i<intervals.size();i++){
            auto interval = intervals[i];
            int n=sol.size();
            auto topInterval = sol[--n];
            while((interval[0] <= topInterval[0] && interval[1] >= topInterval[0])
            || (topInterval[0] <= interval[0] && topInterval[1] >= interval[0])){
                sol.pop_back();
                interval[0] = min(interval[0], topInterval[0]);
                interval[1] = max(interval[1], topInterval[1]);
                
                if(sol.size() == 0) break;
                topInterval = sol[--n];
            }
            sol.push_back(interval);
        }
        return sol;
    }
};
