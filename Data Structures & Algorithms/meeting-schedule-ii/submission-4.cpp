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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) -> bool {return a.start < b.start;});
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int maxRooms = 1;
        minHeap.push(intervals[0].end);
        for(int i=1;i<intervals.size();i++){
            auto [b, e] = intervals[i];
            if(b < minHeap.top()){
                minHeap.push(e);
            }else{
                while(minHeap.size() && minHeap.top() <= b){
                    minHeap.pop();
                }
                minHeap.push(e);
            }
            maxRooms = max(maxRooms, (int)minHeap.size());
        } 
        return maxRooms;
    }
};
