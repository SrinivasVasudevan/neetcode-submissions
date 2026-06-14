class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixMul;
        vector<int> suffixMul;
        prefixMul.reserve(nums.size());
        suffixMul.reserve(nums.size());
        int rPrefixMul=1, rSuffixMul=1;
        for(int i=0;i<nums.size();i++){
            prefixMul[i]=rPrefixMul;
            suffixMul[nums.size()-1-i]=rSuffixMul;
            rPrefixMul*=nums[i];
            rSuffixMul*=nums[nums.size()-1-i];
        }
        vector<int> out;
        for(int i=0;i<nums.size();i++){
            out.push_back(prefixMul[i]*suffixMul[i]);
        }
        return out;
    }
};
