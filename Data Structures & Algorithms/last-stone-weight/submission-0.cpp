class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &s: stones){
            pq.push(s);
        }
        while(!pq.empty()){
            if(pq.size() == 1) return pq.top();
            else{
                int first = pq.top();
                pq.pop();
                int second = pq.top();
                pq.pop();
                if(first != second){
                    pq.push(abs(first-second));
                }
            }
        }
        return 0;
    }
};
