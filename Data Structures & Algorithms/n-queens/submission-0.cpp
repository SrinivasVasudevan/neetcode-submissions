class Solution {
public:
    int N;
    bool nQueen(vector<vector<string>>& out, vector<string>& temp, int j, vector<int>& h, vector<int>& d1, vector<int>& d2){
        if(j == N) {
            out.push_back(temp);
            return true;
        }
        for(int i = 0; i < N; i++) {
            if(!h[i] && !d1[i+j] && !d2[i-j+N-1]){
                string t(N, '.');
                t[i] = 'Q';
                temp.push_back(t);
                h[i] = 1; d1[i+j] = 1; d2[i-j+N-1] = 1;
                nQueen(out, temp, j + 1, h, d1, d2);
                h[i] = 0; d1[i+j] = 0; d2[i-j+N-1] = 0;
                temp.pop_back();
            }
        }
        return false;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> out;
        N = n;
        vector<int> horizontal(n, 0);
        vector<int> diag1(2*n, 0);
        vector<int> diag2(2*n, 0);
        vector<string> temp;
        nQueen(out, temp, 0, horizontal, diag1, diag2);
        return out;
    }
};