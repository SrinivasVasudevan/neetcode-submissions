class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> gasExtended(gas.size()*2-1, 0);
        vector<int> costExtended(cost.size()*2-1, 0);
        int n = gas.size();
        
        for(int i=1;i<gasExtended.size();i++){
            gasExtended[i] = gas[i%n];
            costExtended[i] = cost[i%n];
        }

        int runningLen=0, runningSum = 0, index = -1;

        for(int i=0;i<gasExtended.size();i++){
            runningSum+=(gas[i%n]-cost[i%n]);
            if(runningSum>=0) runningLen++;
            else {runningSum = 0; runningLen=0;}
            
            if(runningLen == n){
                index = i-n+1;
            }
        }

        return index;
        
    }
};
