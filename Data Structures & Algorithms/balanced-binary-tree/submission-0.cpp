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
    int dfs(TreeNode* node, int& maxHeightDiff){
        if(node == nullptr) return 0;
        int left = dfs(node->left, maxHeightDiff);
        int right = dfs(node->right, maxHeightDiff);
        maxHeightDiff = std::max(maxHeightDiff, std::abs(right-left));
        return std::max(left, right)+1;
    }
    bool isBalanced(TreeNode* root) {
        int maxHeightDiff = 0;
        dfs(root, maxHeightDiff);
        if(maxHeightDiff > 1) return false;
        return true;
    }
};
