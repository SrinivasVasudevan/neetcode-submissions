class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        for(int index=0;index<numbers.size();index++){
            if(mp.find(target-numbers[index])!=mp.end()){
                return {mp[target-numbers[index]]+1,index+1};
            }
            mp[numbers[index]]=index;
        }
        return {-1,-1};
    }
};
