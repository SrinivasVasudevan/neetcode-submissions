class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<int> maxProfit(N, 0);
        for(int i=1;i<N;i++){
            for(int j=i-1;j>=0;j--){
                int profit = prices[i] - prices[j];
                if(j-2>=0){
                    profit = profit + maxProfit[j-2];
                }
                maxProfit[i] = max(maxProfit[i], profit);
            }
            maxProfit[i] = max(maxProfit[i], maxProfit[i-1]);
        }
        return maxProfit[N-1];
    }
};
