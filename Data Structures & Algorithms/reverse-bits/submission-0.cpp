class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t bitMask=pow(2,31);
        uint32_t revBitMask=pow(2,0);
        uint32_t sol=0;
        while(bitMask){
            if(revBitMask&n) sol=sol|bitMask;
            bitMask=bitMask>>1;
            revBitMask=revBitMask<<1;
        }
        return sol;
    }
};
