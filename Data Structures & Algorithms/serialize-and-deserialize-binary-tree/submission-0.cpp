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

class Codec {
public:

    // Encodes a tree to a single string.
    void sz(TreeNode* node, string& s){
        if(!node){
            s+="#;";
            return;
        }
  
        s+=to_string(node->val)+";";
        sz(node->left, s);
        sz(node->right, s);
        return;
    }

    string serialize(TreeNode* root) {
        string serial = "";
        sz(root, serial);
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* dz(string& currData){
        string currChar = currData.substr(0, currData.find(';'));
        currData = currData.erase(0,currData.find(';')+1);
        if(currChar == "#") return nullptr;
        TreeNode* node = new TreeNode(std::stoi(currChar));
        
        node->left = dz(currData);
        node->right = dz(currData);
        return node;
    }
    TreeNode* deserialize(string data) {
        cout<<data<<endl;
        return dz(data);
    }
};
