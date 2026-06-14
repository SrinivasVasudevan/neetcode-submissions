class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> d;
        vector<int> out;
        int l=0,r=0;
        while(r<nums.size()){
            while(!d.empty() && nums[d.back()] < nums[r]){
                d.pop_back();
            }
            d.push_back(r);
            if(!d.empty() && d.front() < l) d.pop_front();
            if(r+1 >= k){
                out.push_back(nums[d.front()]);
                l++;
            }
            r++;
        }   
        return out;
    }
};
