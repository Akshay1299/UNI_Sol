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
    string dfs(TreeNode * root)
    {
        if(root==nullptr)
        {
            return "";
        }
        std::string s;
        s+=to_string(root->val);
        if(root->right==nullptr && root->left==nullptr)
        {
            //do nothing
        }
        else if(root->right==nullptr)
        {
            s+="("+dfs(root->left)+")";
        }
        else if(root->left==nullptr)
        {
            s+="()";
            s+="("+dfs(root->right)+")";
        }
        else 
            s+= "("+dfs(root->left)+")"+
                "("+dfs(root->right)+")";
        return std::move(s);
    }
    string tree2str(TreeNode* root) 
    {
        std::string s = dfs(root);
        return s;
    }
};