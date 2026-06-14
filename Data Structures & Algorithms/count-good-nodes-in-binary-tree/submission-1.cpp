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
    void trav(TreeNode* node, int &c, int maxVal){
        if(node==nullptr) return;
        if(maxVal<=node->val) c++;
        trav(node->left, c, max(maxVal, node->val));
        trav(node->right, c, max(maxVal, node->val));
    }
    int goodNodes(TreeNode* root) {
        int c=0;
        trav(root, c, root->val);
        return c;
    }
};
