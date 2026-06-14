class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> sol;
        int i=0, N=intervals.size();
        while(i<N && intervals[i][1] < newInterval[0]){
            sol.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        cout<<i<<endl;
        int start = newInterval[0];
        int end = newInterval[1];
        //cout<<intervals[i][0] <= start && start <= intervals[i][1]<<" "<<intervals[i][0] <= end <= intervals[i][1]<<endl;
        while(i<N && ((intervals[i][0] <= start && start <= intervals[i][1]) || (intervals[i][0] <= end && end <= intervals[i][1])
        || (intervals[i][0] <= start && end <= intervals[i][1])
        || (intervals[i][0] >= start && end >= intervals[i][1])
        )) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        cout<<i<<endl;
        
        sol.push_back({start, end});

        while(i<N){
            sol.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }

        return sol;
    }
};
