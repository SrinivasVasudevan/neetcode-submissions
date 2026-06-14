class MedianFinder {
public:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size()==0){
            maxHeap.push(num);
        }else{
            if(maxHeap.top()>num){
                maxHeap.push(num);
            }else{
                minHeap.push(num);
            }
            int diff=maxHeap.size()-minHeap.size();
            if(abs(diff) > 1){
                if(maxHeap.size() > minHeap.size()){
                    int transfer=maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(transfer);
                }else{
                    int transfer=minHeap.top();
                    minHeap.pop();
                    maxHeap.push(transfer);
                }
            }
        }
    }
    
    double findMedian() {
        if((minHeap.size()+maxHeap.size())%2!=0){
            if(maxHeap.size()>minHeap.size()) return maxHeap.top();
            else return minHeap.top();
        }else{
            return (minHeap.top()+maxHeap.top())/2.0f;
        }
    }
};
