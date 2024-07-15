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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        const int N = 100001;
        int root = -1;
        vector<bool> visited(N, false);
        vector<int> parent(N, 0);
        vector<TreeNode*> nodes(N, NULL);
        for (auto& node : descriptions) {
            int val = node[0], child = node[1], isLeft = node[2];
            if (!visited[val]) {
                nodes[val] = new TreeNode(val);
                visited[val] = 1;
                if (parent[val] == 0) root = val;
            }
            if (!visited[child]) {
                nodes[child] = new TreeNode(child);
                visited[child] = 1;
            }
            parent[child] = val;
            if (isLeft) nodes[val] -> left = nodes[child];
            else nodes[val] -> right = nodes[child];
        }
        while (parent[root] != 0) root = parent[root];
        return nodes[root];
    }
};