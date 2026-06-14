class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board){
        if(r<0||c<0||r>board.size()-1||c>board[0].size()||board[r][c]=='A'||board[r][c]=='X') return;
        board[r][c]='A';
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto d: dirs){
            int nr = r+d[0];
            int nc = c+d[1];
            dfs(nr,nc,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int r=0;r<board.size();r++){
            dfs(r,0,board);
        }
        for(int r=0;r<board.size();r++){
            dfs(r,board[0].size()-1,board);
        }
        for(int c=0;c<board[0].size();c++){
            dfs(0,c,board);
        }
        for(int c=0;c<board[0].size();c++){
            dfs(board.size()-1,c,board);
        }
        for(int r=0;r<board.size();r++){
            for(int c=0;c<board[0].size();c++){
                if(board[r][c]=='O'){
                    board[r][c]='X';
                }else if(board[r][c]=='A'){
                    board[r][c]='O';
                }
            }
        }
    }
};
