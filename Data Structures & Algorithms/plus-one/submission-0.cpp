class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> sol;
        int balance = 1;
        for(int i=digits.size()-1;i>=0;i--){
            int val = (digits[i]+balance)%10;
            balance = (digits[i]+balance)/10;
            sol.push_back(val);
        }
        if(balance){
            sol.push_back(balance);
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
