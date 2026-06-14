class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=heights.size()-1;
        int out=0;
        while(i<j){
            //cout<<i<<" "<<j<<" "<<heights[j]<<" "<<heights[i]<<" "<<min(heights[j],heights[i])<<endl;
            out=max(out, min(heights[j],heights[i])*(j-i));
            if(heights[j]>heights[i]) i++;
            else if(heights[j]<=heights[i]) j--;
        }
        return out;
    }
};
