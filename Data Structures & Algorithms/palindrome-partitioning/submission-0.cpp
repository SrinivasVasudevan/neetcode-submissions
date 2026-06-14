class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> solution;
        vector<string> intermediate;
        auto isPalindrome = [&](this auto&& self, string check) -> bool {
            int i=0,j=check.length()-1;
            while(i<j){
                if(check[i++]!=check[j--]) return false;
            }
            return true;
        };

        auto dfs = [&](this auto&& self, int i, int j) -> void {
            if(j==s.length()+1){
                if(i==s.length()) solution.push_back(intermediate);
                return;
            }
            cout<<i<<" "<<j-i<<endl;
            cout<<s.substr(i, j-i+1)<<" "<<isPalindrome(s.substr(i, j-i))<<endl;
            if(isPalindrome(s.substr(i, j-i))){
                intermediate.push_back(s.substr(i, j-i));
                self(j,j+1);
                intermediate.pop_back();
            }
            
            self(i,j+1);
            return;
        };
        cout<<s.length()<<endl;
        dfs(0, 1);
        return solution;

    }
};
