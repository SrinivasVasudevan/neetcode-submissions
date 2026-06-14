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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        std::queue<TreeNode*> temp;
        if(root) temp.push(root);
        while(!temp.empty()){
            int s = temp.size();
            vector<int> sol_int;
            while(s--){
                sol_int.push_back(temp.front()->val);
                TreeNode* tempNode = temp.front();
                if(tempNode->left) temp.push(tempNode->left);
                if(tempNode->right) temp.push(tempNode->right);
                temp.pop();
            }
            sol.push_back(sol_int);
        }
        return sol;
        
    }
};
