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
    int ht[100004]={};
    int mx=0;
    void preorderL(TreeNode* root,int cht){
        if(!root) return;
        ht[root->val] = mx;
        mx = max(mx,cht);
        preorderL(root->left,cht+1);
        preorderL(root->right,cht+1);
    }
    void preorderR(TreeNode* root,int cht){
        if(!root) return;
        ht[root->val] = max(mx,ht[root->val]);
        mx = max(mx,cht);
        preorderR(root->right,cht+1);
        preorderR(root->left,cht+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        if(!root) return {};
        preorderL(root,0);
        mx=0;
        preorderR(root,0);
        vector<int> ans;
        for(auto&i:queries) ans.push_back(ht[i]);
        return ans;
    }
};