class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> sol;
        int i = 0;
        while(i<intervals.size()){
            auto interval = intervals[i];
            if((interval[0] > newInterval[0] && interval[0] > newInterval[1])){
                break;
            }else{
                sol.push_back(interval);
            }
            i++;
        }
        int n = sol.size();
        while(sol.size()>0){
            auto interval = sol[n-1];
            if((interval[0] >= newInterval[0] && interval[0] <= newInterval[1])
            || (newInterval[0] >= interval[0] && newInterval[0] <= interval[1])){
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
                sol.pop_back();
                n--;
            }else{
                break;
            }
        }
        sol.push_back(newInterval);
        while(i<intervals.size()){
            auto interval = intervals[i];
            sol.push_back(interval);
            i++;
        }
        return sol;
    }
};
