class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> digMap={
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}}
        };
        vector<string> solution;
        string s;
        if(digits=="")return solution;
        auto gen = [&](this auto&& self, int i, string s) -> void {
            if(i==digits.length()){
                solution.push_back(s);
                return;
            }
            cout<<i<<" "<<s<<endl;
            for(int k=0;k<digMap[digits[i]].size();k++){
                s+=digMap[digits[i]][k];
                //cout<<s<<endl;
                self(i+1,s);
                s.pop_back();
            }
        };
        gen(0,"");
        return solution;

    }
};
