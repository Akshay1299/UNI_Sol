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

// Already Solved!
class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if(not root) return root;
		if(root->val>key){
			root->left=deleteNode(root->left,key);
		}
		else if(root->val<key){
			root->right=deleteNode(root->right,key);
		}
		else{
			if(not root->left){
				return root->right;
			}
			else if(not root->right){
				return root->left;
			}
			else{
				TreeNode* tem=root->right;
				while(tem->left){
					tem=tem->left;
				}
				root->val=tem->val;
				root->right=deleteNode(root->right,tem->val);
			}       
		}
		return root;
	}
};