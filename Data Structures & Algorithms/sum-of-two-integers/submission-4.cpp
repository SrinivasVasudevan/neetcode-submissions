class Solution {
public:
    int getSum(int a, int b) {
        int sol=a^b;
        int carry=a&b;
        while(carry){
            carry=carry<<1;
            int inter=sol^carry;
            carry=sol&carry;
            sol=inter;
        }
        return sol;
    }
};
