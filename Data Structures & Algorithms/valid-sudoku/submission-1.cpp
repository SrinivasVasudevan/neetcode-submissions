class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> vertical(10, vector<int>(10));
        vector<vector<int>> horizontal(10, vector<int>(10));
        vector<vector<int>> grid(10, vector<int>(10));
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                cout<<board[i][j]<<" "<<vertical[j][board[i][j]-48]<<" "<<horizontal[i][board[i][j]-48]<<" "<<grid[i/3+3*(j/3)][board[i][j]-48]<<endl;
                if(vertical[j][board[i][j]-48]!=0 
                    || horizontal[i][board[i][j]-48]!=0 
                    || grid[i/3+3*(j/3)][board[i][j]-48]!=0) return false;
                vertical[j][board[i][j]-48]=1;
                grid[i/3+3*(j/3)][board[i][j]-48]=1;
                horizontal[i][board[i][j]-48]=1;
            }
        }
        return true;
    }
};
