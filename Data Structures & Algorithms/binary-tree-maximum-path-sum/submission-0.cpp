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
    int traverse(TreeNode* node, int& maxSoFar){
        if(node==nullptr) return 0;
        int left = traverse(node->left, maxSoFar);
        int right = traverse(node->right, maxSoFar);
        int sum = left + right + node->val;
        maxSoFar = max(maxSoFar, max(sum, max(right,left)+node->val));
        return max(max(left, right)+node->val,0);

    }
    int maxPathSum(TreeNode* root) {
        int maxSoFar=-1000000;
        traverse(root, maxSoFar);
        return maxSoFar;
    }
};
