class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int times = N/2;
        int start=0;
        while(times--){
            for(int i=start;i<N-1-start;i++){
                swap(matrix[start][i], matrix[i][N-1-start]);
            }
            for(int i=start;i<N-1-start;i++){
                swap(matrix[start][i], matrix[N-1-start][N-1-i]);
            }
            for(int i=start;i<N-1-start;i++){
                swap(matrix[start][i], matrix[N-1-i][start]);
            }
            start++;
        }
        
    }
};
