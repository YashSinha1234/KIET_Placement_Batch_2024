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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
    
    int solve(TreeNode *root, int &ans) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            ans = max(ans, root->val);
            return root->val;
        }
        int left = solve(root->left, ans), right = solve(root->right, ans);
        int currMax = max(root->val, max(left + root->val, right + root->val));
        ans = max(currMax, max(left + right + root->val, ans));
        return currMax;
    }
};