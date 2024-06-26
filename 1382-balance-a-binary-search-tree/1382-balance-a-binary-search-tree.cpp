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

    void sortValues(TreeNode* root, vector<int>& arr)
    {
        if(root == NULL)
          return;
        
        sortValues(root->left, arr);
        arr.push_back(root->val);
        sortValues(root->right, arr);
    }

    TreeNode* balanceTree(vector<int>& arr, int start, int end)
    {
        if(start > end || start == -1 || end == -1)
         return NULL;

        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = balanceTree(arr, start, mid-1);
        root->right = balanceTree(arr, mid+1, end);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> sortedArr;
        sortValues(root, sortedArr);
        return balanceTree(sortedArr, 0, sortedArr.size()-1);
    }
};