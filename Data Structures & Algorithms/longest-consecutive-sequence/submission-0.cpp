class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxLen=0;
        for(int& n: nums){
            mp[n]=1;
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]+1)!=mp.end()) continue;
            else{
                int runLen=1,checkNum=nums[i]-1;
                while(mp.find(checkNum)!=mp.end()){
                    runLen+=1;
                    checkNum-=1;
                }
                maxLen=max(maxLen,runLen);
            }
        }
        return maxLen;
    }
};
