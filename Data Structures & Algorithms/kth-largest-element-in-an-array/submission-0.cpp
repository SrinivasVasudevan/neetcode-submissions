class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto n: nums){
            if(pq.size() < k){
                pq.push(n);
            }else{
                int top=pq.top();
                if(top<n){
                    pq.pop();
                    pq.push(n);
                }
            }
        }
        return pq.top();
    }
};
