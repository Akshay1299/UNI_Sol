/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    
    void solve(vector<vector<int>>& ans, TreeNode* root, int x,
               vector<int>& v) {
        if (!root)
            return;
        cout << x << endl;
        if (!root->right and !root->left) {
            if (root->val == x)
                {
                    v.push_back(x);
                    ans.push_back(v);
                    v.pop_back();
                }
            return;
        }
        v.push_back(root->val);
        solve(ans, root->right, x - root->val, v);
        solve(ans, root->left, x - root->val, v);
        v.pop_back();
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans, root, targetSum, v);
        return ans;
    }
};