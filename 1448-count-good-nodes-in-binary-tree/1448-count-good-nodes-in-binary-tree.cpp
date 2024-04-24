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
    int numsgood(TreeNode* root, int ex){
        if(root==nullptr)
           return 0;
        if(root->val>=ex){
           return numsgood(root->left, root->val) + numsgood(root->right, root->val) + 1;
        }else{
           return numsgood(root->left, ex) + numsgood(root->right, ex);
        }
    }
    int goodNodes(TreeNode* root) {
        return numsgood(root, root->val);
    }
};