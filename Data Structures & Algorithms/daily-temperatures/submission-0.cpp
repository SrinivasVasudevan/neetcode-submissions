class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n=temperatures.size()-1;
        vector<int> out(n+1,0);
        s.push(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && temperatures[s.top()] <= temperatures[i]){
                s.pop();
            }
            if(!s.empty()){
                out[i]=s.top()-i;
            }
            s.push(i);
        }
        return out;
    }
};
