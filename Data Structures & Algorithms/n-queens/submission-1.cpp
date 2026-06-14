class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solution;
        vector<string> board;
        string boardEmpty="";
        for(int i=0;i<n;i++){
            boardEmpty+=".";
        }
        for(int i=0;i<n;i++){
            board.push_back(boardEmpty);
        }
        
        vector<bool> hPossible(2*n, true);
        vector<bool> diag1(2*n,true);
        vector<bool> diag2(2*n,true);

        auto nQueen = [&](this auto&& self, int c) -> void {
            if(c==n){
                solution.push_back(board);
                return;
            }
            for(int i=0;i<n;i++){
                if(hPossible[i]&&diag1[i+c]&&diag2[c-i+n]){
                    board[i][c]='Q';
                    hPossible[i]=false;
                    diag1[i+c]=false;
                    diag2[c-i+n]=false;
                    self(c+1);
                    hPossible[i]=true;
                    diag1[i+c]=true;
                    diag2[c-i+n]=true;
                    board[i][c]='.';
                }
            }
        };
        nQueen(0);
        return solution;

    }
};
