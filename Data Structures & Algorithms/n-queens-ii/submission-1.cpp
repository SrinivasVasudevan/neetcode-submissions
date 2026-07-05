class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> row, maj_diag, min_diag;
        row = vector<int>(n,0); 
        maj_diag = vector<int>(2*n, 0);
        min_diag = vector<int>(2*n, 0);

        auto dfs = [&](this auto&& self, int r, int c) -> void {
            if(row[r] || maj_diag[r+c] || min_diag[r-c+n]) return;
            if(c == n){
                res++;
                return;
            }
            row[r] = 1;
            maj_diag[r+c] = 1;
            min_diag[r-c+n] = 1;
            for(int k = 0; k < n; k++){
                self(k, c+1);
            }
            row[r] = 0;
            maj_diag[r+c] = 0;
            min_diag[r-c+n] = 0;
        };
        for(int k=0;k<n;k++){
            // row[k] = 1;
            // maj_diag[k] = 1;
            // min_diag[k+n] = 1;
            dfs(k, 1);
            // row[k] = 0;
            // maj_diag[k] = 0;
            // min_diag[k+n] = 0;
        }
        
        
        return res;
    }
};