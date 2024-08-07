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
    void traverse(TreeNode* node, int& ans, int targetSum, vector<long>& sums) {
        if(!node) return;
        vector<long> hereSums(sums.begin(), sums.end());
        hereSums.push_back(node->val);
        if(node->val == targetSum) ans++;
        for(long i=0; i<hereSums.size()-1; i++) {
            hereSums[i] += node->val;
            if(hereSums[i] == targetSum) ans++;
        }
        traverse(node->left, ans, targetSum, hereSums);
        traverse(node->right, ans, targetSum, hereSums);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        vector<long> sums;
        traverse(root, ans, targetSum, sums);
        return ans;
    }
};