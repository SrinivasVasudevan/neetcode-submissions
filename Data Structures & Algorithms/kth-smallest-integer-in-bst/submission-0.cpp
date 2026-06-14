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
    void kval(TreeNode* n, int& c, int k, int& ans){
        if(!n) return;
        kval(n->left, c, k, ans);
        c++;
        if(c == k) ans = n->val;
        kval(n->right, c, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        int ans=0;
        kval(root, c, k, ans);
        return ans;
    }
};
