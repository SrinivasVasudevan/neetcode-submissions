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
    bool same; 
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(!root&&!subRoot) return true;
        else if(!root||!subRoot) return false;
        if(root->val!=subRoot->val) return false;
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
    void trav(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr) return;
        if(root->val == subRoot->val){
            same = same || isSame(root, subRoot);
            //cout<<"what?"<<endl;
        }
            trav(root->left, subRoot);
            trav(root->right, subRoot);
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        same = false;
        trav(root, subRoot);
        return same;
    }
};
