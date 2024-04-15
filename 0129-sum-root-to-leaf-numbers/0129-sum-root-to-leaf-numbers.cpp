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
    void helper (TreeNode *root, int &totalSum, int sumTillCurrNode) {
        if (root == nullptr)
            return; 
        sumTillCurrNode = sumTillCurrNode * 10 + root -> val;
        if (root -> left == nullptr && root -> right == nullptr)
            totalSum += sumTillCurrNode;
        helper(root -> left, totalSum, sumTillCurrNode);
        helper(root -> right, totalSum, sumTillCurrNode);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper (root, sum, 0);
        return sum;
    }
};