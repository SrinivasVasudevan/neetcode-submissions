class LRUCache {
public:
    int capacity;
    
    class Node{
        public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v): key(k), value(v){
            next=nullptr;
            prev=nullptr;
        }
    };

    Node* front;
    Node* back;

    unordered_map<int, Node*> mp;

    LRUCache(int capacity): capacity(capacity) {
        front = new Node(-1, -1);
        back = new Node(-1, -1);
        front->next=back;
        back->prev=front;
    }

    Node* remove_key(Node* found){
        Node* prev = found->prev;
        Node* curr = found;
        Node* nxt = found->next;
        
        prev->next = nxt;
        nxt->prev = prev;
        return curr;
    }

    void insert_node(Node* node){
        Node* bback = back->prev;
        bback->next = node;
        node->prev = bback;

        node->next = back;
        back->prev = node;
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node* rk = remove_key(mp[key]);
            insert_node(rk);
            return rk->value;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* rk = remove_key(mp[key]);
            rk->value = value; 
            insert_node(rk);
            return;
        }else{
            if(mp.size() == capacity){
                Node* rk = remove_key(front->next);
                mp.erase(rk->key);
                delete rk;
            }
            Node* newnode = new Node(key, value);
            mp[key] = newnode;
            insert_node(newnode);
        }
    }
};
