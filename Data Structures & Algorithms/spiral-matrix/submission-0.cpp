class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int N=matrix.size(), M=matrix[0].size();
        int left=0,right=M,top=0,bottom=N;
        vector<int> out;
        while(left < right && top < bottom){
            for(int i=left;i<right;i++){
                out.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<bottom;i++){
                out.push_back(matrix[i][right-1]);
            }
            right--;
            if(!(left < right && top < bottom)) break;
            for(int i=right-1;i>=left;i--){
                out.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            for(int i=bottom-1;i>=top;i--){
                out.push_back(matrix[i][left]);
            }
            left++;
        }
        return out;
    }
};
