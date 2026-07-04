class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> min_cost(n, INT_MAX);

        if(n == 2){
            return min(cost[0], cost[1]);
        }else if(n <= 1){
            return 0;
        }
        min_cost[0] = 0;
        min_cost[1] = 0;
        int total_cost = 0;
        for(int i=2;i<min_cost.size();i++){
            min_cost[i] = min(min_cost[i-1]+cost[i-1], min_cost[i-2]+cost[i-2]);
        }

        return min(cost[n-1]+min_cost[n-1], cost[n-2]+min_cost[n-2]);
    }
};
