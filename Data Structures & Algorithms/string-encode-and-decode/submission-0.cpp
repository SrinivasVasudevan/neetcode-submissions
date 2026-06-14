class Solution {
public:

    string encode(vector<string>& strs) {
        string e="";
        for(string& s:strs){
            e+=s;
            e+=";";
        }
        //e.erase(e.size()-1,1);
        return e;
    }

    vector<string> decode(string s) {
        vector<string> out;
        while(s.size()>0){
            out.push_back(s.substr(0,s.find(";")));
            s.erase(0,s.find(";")+1);
        }
        return out;
    }
};
