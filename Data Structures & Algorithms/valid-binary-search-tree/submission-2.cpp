/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool trav(TreeNode* node, int l, int r){
        if(!node) return true;
        
        if(node->val > l && node->val < r){
            bool left = trav(node->left, l ,node->val);
            if(!left) return false;
            bool right = trav(node->right, node->val, r);
            if(!right) return false;

            if(left && right) return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return trav(root,-1001,1001);
    }
};
