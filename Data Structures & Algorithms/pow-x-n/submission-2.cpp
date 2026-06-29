class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==0 || n==1) return x;

        int power = abs(n);
        double res = 1;
        while(power){
            if(power & 1){
                res = res * x;
            }
            x*=x;
            power = power >> 1;
        }

        return n>0 ? res : 1/res;
    }
};
