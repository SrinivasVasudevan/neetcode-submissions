class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool valid=false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        auto dfs=[&](this auto&& self, int i, int j, int k){
            if(k==word.size()-1){
                valid=true;
                return;
            }
            cout<<i<<" "<<j<<" "<<k<<endl;
            if(i+1<board.size() && visited[i+1][j]==false && word[k+1]==board[i+1][j]){
                visited[i+1][j]=true;
                self(i+1,j,k+1);
                visited[i+1][j]=false;
            }
            if(i-1>=0 && visited[i-1][j]==false && word[k+1]==board[i-1][j]){
                visited[i-1][j]=true;
                self(i-1,j,k+1);
                visited[i-1][j]=false;
            }
            if(j+1<board[0].size() && visited[i][j+1]==false && word[k+1]==board[i][j+1]){
                visited[i][j+1]=true;
                self(i,j+1,k+1);
                visited[i][j+1]=false;
            }
            if(j-1>=0 && visited[i][j-1]==false && word[k+1]==board[i][j-1]){
                visited[i][j-1]=true;
                self(i,j-1,k+1);
                visited[i][j-1]=false;
            }
            return;
        };
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    visited[i][j]=true;
                    dfs(i,j,0);
                    visited[i][j]=false;
                    if(valid) return true;
                }
            }
        }
        return valid;
    }
};
