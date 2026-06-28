/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto a, auto b)->bool{return a.start < b.start;});
        
        auto interval = intervals[0];
        for(int i=1;i<intervals.size();i++){
            auto newInterval = intervals[i];
            if(newInterval.start < interval.end){
                return false;
            }else{
                interval = newInterval;
            }
        }
        return true;
    }
};
