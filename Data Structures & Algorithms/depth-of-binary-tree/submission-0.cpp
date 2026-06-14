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
    int maxValue(TreeNode* node){
        if(node == nullptr) return 0;
        return max(maxValue(node->left)+1, maxValue(node->right)+1);
    }
    int maxDepth(TreeNode* root) {
        return maxValue(root);
     }
};
