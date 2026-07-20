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
//dfs? implementation?
// When I recurse down the tree, what information do I need to carry with me so that every descendant knows all the restrictions placed on it by its ancestors?
    bool solve(TreeNode* root, int lower_bound, int upper_bound){
        if(!root) return true;
        if(root->val <= lower_bound || root->val >= upper_bound) return false;
        return solve(root->left, lower_bound, root->val) && solve(root->right, root->val, upper_bound);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, INT_MIN, INT_MAX);
    }
};
