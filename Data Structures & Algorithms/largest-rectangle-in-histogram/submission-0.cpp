class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int a=0;
        stack<pair<int,int>> st;
        st.push(make_pair(heights[0],1));
        heights.push_back(0);
        for(int i=1;i<heights.size();i++){
            int t=0,c=0;
            while(!st.empty() && st.top().first >= heights[i]){
                t=st.top().first,c+=st.top().second;
                a=max(a,c*t);
                st.pop();
            }
            st.push(make_pair(heights[i],c+1));
        }
        return a;
    }
};
