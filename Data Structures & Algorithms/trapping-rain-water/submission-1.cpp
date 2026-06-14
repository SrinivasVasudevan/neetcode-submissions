class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=0,rightMax=0;
        int i=0,j=height.size()-1;
        int out=0;
        while(i<j){
            leftMax=max(leftMax,height[i]);
            rightMax=max(rightMax,height[j]);
            int limit=min(leftMax, rightMax);
            if(height[i]<height[j]){
                out+=max(limit-height[i],0);
                i++;
            }else{
                out+=max(limit-height[j],0);
                j--;
            }
            cout<<out<<" "<<limit<<" "<<i<<" "<<j<<endl;
            
        }
        return out;
    }
};
