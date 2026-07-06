class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> char_order;
        for(int i=0;i<order.size();i++){
            char_order[order[i]]=i;
        }


        for(int i=0;i<words.size()-1;i++){
            string w1 = words[i], w2 = words[i+1];
            int min_len = min(w1.size(), w2.size());
            if(w1.substr(0, min_len) == w2.substr(0, min_len) && w1.size() > w2.size()) return false;
            for(int l=0;l<min_len;l++){
                if(w1[l] == w2[l]) continue;
                if(char_order[w1[l]] > char_order[w2[l]]) return false;
                break;
            }
        }
        return true;
    }
};