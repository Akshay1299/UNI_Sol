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
    int solve(TreeNode* root,TreeNode* parent){
        if(root==NULL)return 0;
        int moves=solve(root->left,root)+solve(root->right,root);;
        int x=root->val-1;
        if(parent!=NULL)parent->val+=x;
        moves+=abs(x);
        return moves;
    }
    int distributeCoins(TreeNode* root) {
        return solve(root,NULL);
    }
};