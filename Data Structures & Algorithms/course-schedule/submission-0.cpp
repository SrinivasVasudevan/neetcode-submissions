class Node{
    public:
    int val;
    vector<Node*> dependent;
    Node(){
        val=-1;
    }
    Node(int v){
        val=v;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, Node*> courseNodes;
        for(int c=0;c<numCourses;c++){
            courseNodes[c]=new Node(c);
        }
        for(auto cd: prerequisites){
            int pre=cd[1];
            int d=cd[0];
            courseNodes[pre]->dependent.push_back(courseNodes[d]);
        }

        //we do dfs
        //when evicted, we finished visiting 
        //in the dfs if we see the node again, we are in a cycle
        vector<int> visited(numCourses, -1);
        //bool cyclePresent=false;

        auto detectCycle = [&](this auto&& self, Node* currNode) -> bool {
            if(currNode->dependent.size()==0) return false;
            
            for(int i=0;i<currNode->dependent.size();i++){
                Node* dep = currNode->dependent[i];
                if(visited[dep->val]==-1){
                    visited[dep->val]=0;
                    if(self(dep)) return true;
                    visited[dep->val]=1;
                }else if(visited[dep->val]==0){
                    return true;
                }else if(visited[dep->val]==1){
                    continue;
                }
            }
            return false;
        };

        for(int i=0;i<numCourses;i++){
            if(visited[i]==-1){
                visited[i]=0;
                if(detectCycle(courseNodes[i])) return false;
                visited[i]=1;
                
            }
        }
        
        return true;

    }
};
