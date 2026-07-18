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
//dfs(1)->
class Solution {
public:
    bool ans = true;
    void dfs(TreeNode *p, TreeNode* q){
        if(!ans) return;
        if(p == nullptr && q == nullptr){
            return;
        }
        if(p == nullptr || q == nullptr || (p->val != q->val)){
            ans = false;
            return;
        } 
        dfs(p->left, q->left);
        dfs(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, q);
        return ans;
    }
};
