class KthLargest {
public:
    priority_queue<int, vector<int>,greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto n:nums){
            if(pq.size()<K){
                pq.push(n);
            }else{
                if(pq.top() < n)
                {pq.pop();
                pq.push(n);}
            }
        }
        
    }
    
    int add(int val) {
        int retVal = 0;
        if(pq.size()<K){
            pq.push(val);
        }else{
            if(pq.top() < val)
            {pq.pop();
            pq.push(val);}
            
        }
        retVal = pq.top();
        return retVal;
    }
};
