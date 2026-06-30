class Solution {
public:
    int reverse(int x) {
        bool isNeg = x < 0;
        int res = 0;
        x = isNeg ? x * -1 : x;
        while(x){
            int temp = x%10;
            if((isNeg && (res + temp/10) > (pow(2,31)/10))
            || ((res + temp/10) > ((pow(2,31)-1)/10))
            ){
                return 0;
            }else{
                res = res * 10 + temp;
            }
            x = x/10;
        }
        return isNeg ? -1*res : res;
    }
};
