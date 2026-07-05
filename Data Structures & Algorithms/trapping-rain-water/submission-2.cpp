class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int max_left = height[0], max_right = height[n-1];
        int l = 0, r = n-1;
        int trapped = 0;
        while(l<r){
            if(height[l] <= height[r]){
                trapped += max(0, (min(max_left, max_right) - height[l]));
                l++;
                max_left = max(max_left, height[l]);
            }else{
                trapped += max(0, (min(max_left, max_right) - height[r]));
                r--;
                max_right = max(max_right, height[r]);
            }
        }
        return trapped;
    }   
};
