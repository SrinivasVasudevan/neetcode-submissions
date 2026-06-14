/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        std::stack<Node*> st;
        std::unordered_map<Node*,Node*> reference;
        unordered_map<Node*,bool> visited;
        Node* newNode = new Node(node->val);
        reference[node]=newNode;
        st.push(node);
        while(st.size()){
            Node* originalNode = st.top();
            Node* currNode = reference[originalNode];
            
            st.pop();
            if(visited[originalNode]) continue;
            visited[originalNode]=true;
            for(auto n:originalNode->neighbors){
                Node* newNeighbor;
                if(!reference.count(n)){
                    newNeighbor=new Node(n->val);
                    reference[n]=newNeighbor;
                }else{
                    newNeighbor=reference[n];
                }
                currNode->neighbors.push_back(newNeighbor);
                if(!visited.count(n)) st.push(n);
            }
        }
        return newNode;
    }
};
