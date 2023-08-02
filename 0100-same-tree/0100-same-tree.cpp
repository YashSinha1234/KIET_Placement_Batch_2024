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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q ) return 1;
        if(!p && q) return 0;
        if(!q && p) return 0;
        int a = p->val;
        int b = q->val;
        if(a == b)
        {
            if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            {
                return true;
            }
        }
        return false;
        
    }
};