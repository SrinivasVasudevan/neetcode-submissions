class FreqStack {
public:
    unordered_map<int, int> freq_val;
    priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>> pq;

    int index;

    FreqStack() {
        index = 0;
    }   
    
    void push(int val) {
        freq_val[val]+=1;
        pq.push({freq_val[val], {index, val}});
        index++;
    }
    
    int pop() {
        auto [freq, index_val] = pq.top();
        pq.pop();
        auto [index, val] = index_val;
        freq_val[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */