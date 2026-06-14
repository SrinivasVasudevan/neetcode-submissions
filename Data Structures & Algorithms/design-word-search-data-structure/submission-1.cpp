class WordNode {
    public:
    WordNode *child[26];
    bool isWord;
    WordNode(){
        for(auto i=0;i<26;i++) child[i]=nullptr;
        isWord=false;
    }
};

class WordDictionary {
public:
    WordNode *root;
    WordDictionary() {
        root=new WordNode();
    }
    
    void addWord(string word) {
        WordNode *wordTree=root;
        for(auto c:word){
            int idx=c-'a';
            if(!wordTree->child[idx]) wordTree->child[idx]=new WordNode();
            wordTree=wordTree->child[idx];
        }
        wordTree->isWord=true;
    }
    
    bool search(string word) {
        WordNode *wordTree=root;
        auto dfs=[&](this auto&& self, int i) -> bool {
            cout<<i<<endl;
            if(i==word.length()) return wordTree->isWord;
            if(word[i]=='.'){
                for(int c=0;c<26;c++){
                    if(wordTree->child[c]){
                        WordNode *temp=wordTree;
                        wordTree=wordTree->child[c];
                        if(self(i+1)) return true;
                        wordTree=temp;
                    }
                }
            }else{
                if(wordTree->child[word[i]-'a']){
                    wordTree=wordTree->child[word[i]-'a'];
                    if(self(i+1)) return true;
                }
                
            }
            return false;
        };
        return dfs(0);
    }
};
