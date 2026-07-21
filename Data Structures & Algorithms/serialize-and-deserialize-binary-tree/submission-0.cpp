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
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                result += "#,";
                continue;
            }
            result += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        string token = "";
        while (data[i] != ',') {
            token += data[i];
            i++;
        }
        if(token == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*>q;
        q.push(root);
        i++;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            string token1 = "";
            while (data[i] != ',') {
                token1 += data[i];
                i++;
            }
            if(token1 != "#"){
                node->left = new TreeNode(stoi(token1));
                q.push(node->left);
            }
            i++;
            string token2 = "";
            while (data[i] != ',') {
                token2 += data[i];
                i++;
            }
            if(token2 != "#"){
                node->right = new TreeNode(stoi(token2));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};
