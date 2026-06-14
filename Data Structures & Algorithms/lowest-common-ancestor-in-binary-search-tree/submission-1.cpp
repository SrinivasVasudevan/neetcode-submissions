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
    bool lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root==nullptr) return false;
        bool self = root == p || root == q;
        bool l = lca(root->left, p, q, ans);
        bool r = lca(root->right, p, q, ans);
        if(self && l || self && r || l && r) ans = root;
        return self || l || r;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        lca(root, p, q, ans);
        return ans;
    }
};
