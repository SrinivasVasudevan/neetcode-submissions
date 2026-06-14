class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _val){
            key=0;
            val=_val;
            next=nullptr;
            prev=nullptr;
        }
        Node(){
            key=0;
            val=0;
            next=nullptr;
            prev=nullptr;
        }
    };
    
    unordered_map<int,Node*> mp;
    Node* dummyFirst;
    Node* dummyLast;
    int count;
    int cap;

    LRUCache(int capacity) {
        dummyFirst=new Node(-1);
        dummyLast=new Node(-1);
        dummyFirst->next=dummyLast;
        dummyLast->prev=dummyFirst;
        count=0;
        cap=capacity;
    }

    void deleteNode(Node* delNode){
        delNode->prev->next=delNode->next;
        delNode->next->prev=delNode->prev;
        //delete delNode;
    }
    
    int get(int key) {
        printer();
        if(mp.find(key)==mp.end()) return -1;
        int retVal=mp[key]->val;
        deleteNode(mp[key]);
        put(key, retVal);
        return retVal;
    } 

    void printer(){
        Node* run=dummyFirst;
        while(run!=nullptr){
            cout<<run->val<<" "<<run->key<<endl;
            run=run->next;
        }
        cout<<"done"<<endl;
    }
    
    void put(int key, int value) {
        printer();
        
        if(mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
            Node* newNode = new Node(value);
            newNode->key=key;
            mp[key]=newNode;
            dummyLast->prev->next=newNode;
            newNode->prev = dummyLast->prev;
            newNode->next = dummyLast;
            dummyLast->prev = newNode;
        }else{
            if(count==cap){
                mp.erase(dummyFirst->next->key);
                deleteNode(dummyFirst->next);
                count-=1;
            }
            Node* newNode = new Node(value);
            newNode->key=key;
            mp[key]=newNode;
            dummyLast->prev->next=newNode;
            newNode->prev = dummyLast->prev;
            newNode->next = dummyLast;
            dummyLast->prev = newNode;
            count+=1;
        }
    }
};
