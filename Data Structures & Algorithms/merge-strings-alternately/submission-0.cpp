class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1 = 0, w2 = 0;
        string res = "";

        while(w1 < word1.size() && w2 < word2.size()){
            res+=word1[w1++];
            res+=word2[w2++];
        }
        while(w1 < word1.size()){
            res+=word1[w1++];
        }
        while(w2 < word2.size()){
            res+=word2[w2++];
        }

        return res;
    }
};