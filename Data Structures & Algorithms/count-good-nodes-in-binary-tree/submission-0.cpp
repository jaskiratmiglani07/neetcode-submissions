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
//root will always be there
//mp uses dfs and i have done something similar in the past
    int ans = 0;
    void solve(TreeNode* root, int maxVal){
        if(!root) return;
        if(root->val >= maxVal){
            ans++;
            maxVal = root->val;
        }
        solve(root->left, maxVal);
        solve(root->right, maxVal);
    }
    int goodNodes(TreeNode* root) {
        solve(root, root->val);
        return ans;
    }
};
