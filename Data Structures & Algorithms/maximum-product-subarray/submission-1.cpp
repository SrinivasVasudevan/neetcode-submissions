class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int forward=INT_MIN,backward=INT_MIN;
        int temp=1;
        for(int n:nums){
            temp*=n;
            forward=max(forward, temp);
            if(temp == 0) temp = 1;
        }
        reverse(nums.begin(), nums.end());
        temp=1;
        for(int n:nums){
            temp*=n;
            backward=max(backward, temp);
            if(temp == 0) temp = 1;
        }
        int maxVal=INT_MIN;
        for(int n:nums){
            maxVal=max(maxVal, n);
        }
        maxVal = max(forward, maxVal);
        return max(maxVal, backward);
    }
};
