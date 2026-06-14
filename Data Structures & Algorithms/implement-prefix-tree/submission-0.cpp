class PrefixNode {
public:
    PrefixNode *child[26];
    bool isWord;
    PrefixNode(){
        isWord=false;
        for(auto i=0;i<26;i++) child[i]=nullptr;
    }
};

class PrefixTree {
public:
    PrefixNode* root;
    PrefixTree() {
        root = new PrefixNode();
    }
    
    void insert(string word) {
        PrefixNode* pTree = root;
        int idx=-1;
        for(auto c:word){
            idx = c-'a';
            if(!pTree->child[idx]) pTree->child[idx]=new PrefixNode();
            pTree=pTree->child[idx];
        }
        pTree->isWord=true;
    }
    
    bool search(string word) {
        PrefixNode* pTree = root;
        int idx=-1;
        for(auto c:word){
            idx = c-'a';
            if(!pTree->child[idx]) return false;
            pTree=pTree->child[idx];
        }
        return pTree->isWord;
    }
    
    bool startsWith(string prefix) {
        PrefixNode* pTree = root;
        int idx=-1;
        for(auto c:prefix){
            idx = c-'a';
            if(!pTree->child[idx]) return false;
            pTree=pTree->child[idx];
        }
        return true;
    }
};
