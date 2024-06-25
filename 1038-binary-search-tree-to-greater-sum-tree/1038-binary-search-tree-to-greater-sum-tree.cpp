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
    TreeNode* bstToGst(TreeNode* root) {
        bstToGstHelper(root);
        return root;
    }

private:
    int currSum = 0;
    void bstToGstHelper(TreeNode* root) {
        if (root == nullptr) return;
        bstToGstHelper(root->right);
        int rootVal = root->val;
        root->val += currSum;
        currSum += rootVal;
        bstToGstHelper(root->left);
    }
};