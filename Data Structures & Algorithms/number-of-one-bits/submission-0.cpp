class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        int bitMask=1;
        while(bitMask<=n){
            if(bitMask&n)count++;
            bitMask=bitMask<<1;
        }
        return count;
    }
};
