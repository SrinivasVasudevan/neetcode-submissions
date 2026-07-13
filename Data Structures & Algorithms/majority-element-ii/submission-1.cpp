class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first_ele = 0, first_count = 0;
        int second_ele = 0, second_count = 0;
        for(int i=0;i<nums.size();i++){
            if(first_count == 0 || first_ele == nums[i]){
                first_count+=1;
                first_ele = nums[i];
            }else if(second_count == 0 || second_ele == nums[i]){
                second_count+=1;
                second_ele = nums[i];
            }else{
                first_count-=1;
                second_count-=1;
            }
        }

        vector<int> res;
        first_count = 0; second_count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == first_ele){
                first_count+=1;
            }
            if(nums[i] == second_ele){
                second_count+=1;
            }
        }
        
        
        if(first_count > nums.size()/3){
            res.push_back(first_ele);
        }
        if(second_count > nums.size()/3){
            res.push_back(second_ele);
        }

        return res;
    }
};