class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int erase = 0;
        sort(intervals.begin(), intervals.end());
        vector<int> interval = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < interval[1]){
                interval[0] = min(interval[0], intervals[i][0]);
                interval[1] = min(interval[1], intervals[i][1]);
                erase++;
            }else{
                interval = intervals[i];
            }
        }
        return erase;
    }
};
