class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> unique_word_list;
        
        for(string &word: wordList){
            unique_word_list.insert(word);
        }

        if(!unique_word_list.count(endWord)) return 0;

        unique_word_list.insert(beginWord);
        unordered_map<string, unordered_set<string>> adj_words;

        for(auto word: unique_word_list){
            string unchanged_word = word;
            for(int i=0;i<word.size();i++){
                for(int c=0;c<26;c++){
                    word[i] = (char)c+'a';
                    if(unchanged_word != word && unique_word_list.count(word)){
                        adj_words[unchanged_word].insert(word);
                    }
                    word = unchanged_word;
                }
            }
        }

        //int number_times = 1;
        queue<pair<string, int>> q;
        unordered_map<string, bool> vis;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto [node, time] = q.front();
            vis[node] = true;
            if(node == endWord){
                return time;
            }

            q.pop();
            if(!adj_words.count(node)) continue;
            for(auto adj_word: adj_words[node]){
                if(vis.count(adj_word) && vis[adj_word]) continue;
                q.push({adj_word, time+1});
            }
        }

        return 0;

    }
};
