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
    int findIndex(vector<int>& inorder, int pVal, int start, int end){
        int s=start;
        while(s<=end){
            if(inorder[s] == pVal) return s;
            s++;
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end, int& p){
        if(end<start) return nullptr;
        int pVal = preorder[p];
        TreeNode* node = new TreeNode(pVal);
        p++;
        int ind = findIndex(inorder, pVal, start, end);
        if(ind == -1) return nullptr; // should be impossible
        TreeNode* leftNode = build(preorder, inorder, start, ind-1, p);
        TreeNode* rightNode = build(preorder, inorder, ind+1, end, p);
        node->left = leftNode;
        node->right = rightNode;
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p=0;
        return build(preorder, inorder, 0, inorder.size()-1, p);
    }
};
