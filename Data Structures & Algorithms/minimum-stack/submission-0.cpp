class MinStack {
public:
    vector<int> stackMin;
    vector<int> stack;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push_back(val);
        if(stackMin.size() == 0) stackMin.push_back(val);
        else if(stackMin[stackMin.size()-1] > val){
            stackMin.push_back(val);
        }else{
            stackMin.push_back(stackMin[stackMin.size()-1]);
        }
    }
    
    void pop() {
        stack.pop_back();
        stackMin.pop_back();
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return stackMin[stackMin.size()-1];
    }
};
