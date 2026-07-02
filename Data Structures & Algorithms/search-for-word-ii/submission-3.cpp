class PrefixTree{
    public:
    PrefixTree *child[26];
    bool is_word;
    PrefixTree(){
        for(int i=0;i<26;i++){
            child[i]=nullptr;
            
        }
        is_word = false;
    }

};


class Solution {
public:
    void prefixTreeBuilder(PrefixTree *node, string word, int i){
        if(i == word.size()){
            node->is_word=true;
            return;
        }
        if(node->child[word[i]-'a'] == nullptr) node->child[word[i]-'a'] = new PrefixTree();
        prefixTreeBuilder(node->child[word[i]-'a'], word, i+1);
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree *root = new PrefixTree();
        for(auto w: words){
            prefixTreeBuilder(root, w, 0);
        }

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        vector<string> res;

        auto dfs = [&](this auto&& self, int i, int j, PrefixTree *node, string inter) -> void{
            if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
            if(node->child[board[i][j]-'a']==nullptr || visited[i][j] == true) return;
            node = node->child[board[i][j]-'a'];
            inter += board[i][j];
            visited[i][j] = true;
            if(node->is_word){
                res.push_back(inter);
                node->is_word = false;
            }
            self(i, j+1, node, inter);
            self(i+1, j, node, inter);
            self(i, j-1, node, inter);
            self(i-1, j, node, inter);

            visited[i][j] = false;

        };

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(i, j, root, "");
            }
        }

        return res;
    }
};
