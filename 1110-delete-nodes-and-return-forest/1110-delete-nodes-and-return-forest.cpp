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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> nodes(1001, nullptr);
        vector<TreeNode*> parents(1001, nullptr);
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            nodes[node->val] = node;
            if (node->left) {
                parents[node->left->val] = node;
                q.push(node->left);
            }
            if (node->right) {
                parents[node->right->val] = node;
                q.push(node->right);
            }
        }
        unordered_set<TreeNode*> rest;
        rest.insert(root);
        for (auto del : to_delete) {
            if (parents[del]) {
                if (parents[del]->left and parents[del]->left->val == del) {
                    parents[del]->left = nullptr;
                }
                else if (parents[del]->right and parents[del]->right->val == del) {
                    parents[del]->right = nullptr;
                }
            }
            if (nodes[del]->left)
                rest.insert(nodes[del]->left);
            if (nodes[del]->right)
                rest.insert(nodes[del]->right);
            if (rest.find(nodes[del]) != rest.end()) {
                rest.erase(nodes[del]);
            }
        }
        vector<TreeNode*> ans;
        for (auto node : rest) {
            ans.push_back(node);
        }
        return ans;
    }
};