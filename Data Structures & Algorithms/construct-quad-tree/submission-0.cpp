/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool compare_four(Node* a, Node* b, Node* c, Node* d){
        if(a->isLeaf && b->isLeaf && c->isLeaf && d->isLeaf){
            return (a->val && b->val && c->val && d->val) || (!a->val && !b->val && !c->val && !d->val) ;
        }
        return false;
    }

    Node* construct(vector<vector<int>>& grid) {
        
        auto dfs = [&](this auto&& self, int xl, int xr, int yl, int yr) -> Node* {
            
            if(xl == xr){
                return new Node(grid[xl][yl], 1);
            }
            int xmid = (xl + xr) / 2;
            int ymid = (yl + yr) / 2;

            Node* tl = self(xl, xmid, yl, ymid);
            Node* tr = self(xl, xmid, ymid + 1, yr);
            Node* bl = self(xmid + 1, xr, yl, ymid);
            Node* br = self(xmid + 1, xr, ymid + 1, yr);
            

            if(compare_four(tl, tr, bl, br)){
                return tl;
            }else{
                Node* new_node = new Node(1, 0, tl, tr, bl, br);
                return new_node;
            }

        };

        return dfs(0, grid.size()-1, 0, grid.size()-1);

    }
};