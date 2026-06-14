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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> solution;
        std::queue<TreeNode*> temp;
        if(root) temp.push(root);
        while(!temp.empty()){
            int s=temp.size();
            while(s!=1){
                TreeNode* n=temp.front();
                if(n->left) temp.push(n->left);
                if(n->right) temp.push(n->right);
                temp.pop();
                s--;
            }
            TreeNode* n=temp.front();
            if(n->left) temp.push(n->left);
            if(n->right) temp.push(n->right);
            solution.push_back(n->val);
            temp.pop();
        }
        return solution;
    }
};
