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
    bool height_balanced = true;
    int dfs(TreeNode* root){
        if(!root || !height_balanced) return 0;
        //get the lengths of the left and the right subtrees abs difference <= 1
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(abs(left - right) > 1){
            height_balanced = false;
        }
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return height_balanced;
    }
};
