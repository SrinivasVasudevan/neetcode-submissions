class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1,-1);
        vector<int> rank(edges.size()+1,0);
        vector<int> sol(2,-1);

        for(int i=1;i<=parent.size()-1;i++){
            parent[i]=i;
        }

        auto find = [&](this auto&& self, int node) -> int{
            if(parent[node]==node) return node;
            return parent[node] = self(parent[node]);
        };

        auto un = [&](this auto&& self, int node1, int node2) -> void{
            if(find(node1)==find(node2)){
                sol[0]=node1;
                sol[1]=node2;
            }else{
                int parent1 = find(node1);
                int parent2 = find(node2);
                
                if(rank[parent1]==rank[parent2]){    
                    rank[parent1]++;
                }
                parent[parent2]=parent1;
            }
        };

        for(auto e:edges){
            un(e[0],e[1]);
        }

        return sol;
    }
};
