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
    bool ans = false;
    void sub(TreeNode* root, TreeNode* subRoot){
        if(!ans) return;
        if(root == nullptr && subRoot == nullptr) return;
        if(root == nullptr || subRoot == nullptr){
            ans = false;
            return;
        }
        if(root->val != subRoot->val){
            ans = false;
            return;
        } 
        sub(root->left, subRoot->left);
        sub(root->right, subRoot->right);
    }
    void dfs(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr) return;
        if(root->val == subRoot->val){
            ans = true;
            sub(root, subRoot);
            if(ans) return;
        }
        dfs(root->left, subRoot);
        dfs(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root, subRoot);
        if(ans) return true;
        return false;
    }
};
