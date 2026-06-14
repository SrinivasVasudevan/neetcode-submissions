class PrefixNode{
    public:
    PrefixNode *child[26];
    bool isWord;
    PrefixNode(){
        for(int i=0;i<26;i++) child[i]=nullptr;
        isWord=false;
    }
};
class Solution {
public:
    PrefixNode *root;
    Solution(){
        root=new PrefixNode();
    }
    void prefixTreeBuilder(string word){
        PrefixNode *prefixTree=root;
        for(auto c:word){
            int idx=c-'a';
            if(!prefixTree->child[idx]) prefixTree->child[idx]=new PrefixNode();
            prefixTree=prefixTree->child[idx];
        }
        prefixTree->isWord=true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto w:words){
            prefixTreeBuilder(w);
        }
        vector<string> allWords;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        PrefixNode *prefixTree=root;
        string inter="";
        auto dfs = [&](this auto&& self, int i, int j) -> void {
            if(i<0||j<0||i>=board.size()||j>=board[0].size()) return;
            int idx = board[i][j]-'a';
            if(!visited[i][j]&&prefixTree->child[idx]){
                inter+=board[i][j];
                visited[i][j]=true;
                PrefixNode *temp=prefixTree;
                prefixTree=prefixTree->child[idx];
                if(prefixTree->isWord){
                    allWords.push_back(inter);
                    prefixTree->isWord=false;
                }
                self(i+1,j);
                self(i,j+1);
                self(i-1,j);
                self(i,j-1);
                inter.pop_back();
                visited[i][j]=false;
                prefixTree=temp;
            }
            return;
        };

        for(int r=0;r<board.size();r++){
            for(int c=0;c<board[0].size();c++){
                prefixTree=root;
                dfs(r,c);
            }
        }

        return allWords;
    }
};
