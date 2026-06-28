class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> sol(queries.size(), -1);

        vector<pair<int, int>> queryIndex;
        for(int i=0;i<queries.size();i++){
            queryIndex.push_back({queries[i], i});
        }
        sort(queryIndex.begin(), queryIndex.end());
        sort(intervals.begin(), intervals.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int index = 0;

        for(int i=0;i<queryIndex.size();i++){
            auto [q, qloc] = queryIndex[i];
            while(pq.size()){
                auto [len, e] = pq.top();
                if(e < q) pq.pop();
                else break;
            }

            while(index < intervals.size()){
                if(intervals[index][0] <= q && intervals[index][1] >= q){
                    auto interval = intervals[index];
                    int len = interval[1] - interval[0]+1;
                    pq.push({len, interval[1]});
                    index++;
                }
                else if(intervals[index][1] < q){
                    index++;
                }else{
                    break;
                }
            }

            if(pq.size()){
                sol[qloc] = pq.top().first;
            }
        }

        return sol;
    }
};
