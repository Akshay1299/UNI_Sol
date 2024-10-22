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

    map<int, long long> m;
    vector<long long> levelSums;
    int maxLevel = 0;

    void traverseTree(TreeNode* node, int level){

        if(node == nullptr)
            return;

        levelSums[level-1] += node->val;

        maxLevel = maxLevel>level ? maxLevel : level;

        traverseTree(node->left, level+1);
        traverseTree(node->right, level+1);    

    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        levelSums.assign(100000, 0);

        traverseTree(root, 1);

        if(k>maxLevel)
        return -1;

        sort(levelSums.begin(), levelSums.end(), greater<long long>());
        
        return levelSums[k-1];
                
    }
};