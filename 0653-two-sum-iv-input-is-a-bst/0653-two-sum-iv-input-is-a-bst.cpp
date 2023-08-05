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
    vector<int> mp;
    void traveral(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        traveral(root->left);
        mp.push_back(root->val);
        traveral(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        traveral(root);
        map<int,int> fin;
        for(int i=0;i<mp.size();i++)
        {
            fin.insert({i,mp[i]});

        }
        for(int i=0;i<mp.size();i++)
        {
            int x= mp[i];
            int target =k-x;
            for(int j=0;j<mp.size();j++)
            {
                if(mp[j]==target && i!=j)
                {
                    return true;
                }
            }
        }
        return false;
    }
};