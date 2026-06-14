class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string paren;
        auto dfs=[&](this auto&& self, int open, int close) -> void{
            if(open==n && close==n){
                res.push_back(paren);
                return;
            }
            if(open<n){
                paren+="(";
                self(open+1,close);
                paren.pop_back();
            }
            if(close<open){
                paren+=")";
                self(open,close+1);
                paren.pop_back();
            }
            return;
        };
        dfs(0,0);
        return res;
    }
};
