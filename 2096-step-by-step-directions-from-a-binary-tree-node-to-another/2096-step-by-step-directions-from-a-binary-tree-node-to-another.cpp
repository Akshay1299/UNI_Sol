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
    TreeNode* LCA(TreeNode* root, int s,int d){
        if(root == NULL) return NULL;

        if(root->val == s || root->val == d){
            return root;
        }

        TreeNode* l = LCA(root->left,s,d);
        TreeNode* r = LCA(root->right,s,d);

        if(l && r) return root;

        return l? l:r;

    }
    bool findPath(TreeNode* lca_node, int target, string& path){
        if(lca_node == NULL) return false;
        if(lca_node->val == target) return true;

        // explore left
        path.push_back('L');
        if(findPath(lca_node->left,target,path)) return true;
        path.pop_back();

        //explore right
        path.push_back('R');
        if(findPath(lca_node->right,target,path)) return true;
        path.pop_back();

        return false;



    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode * lca = LCA(root, startValue , destValue);

        string lca_to_src = "";
        string lca_to_des = "";

        findPath(lca, startValue , lca_to_src);
        findPath(lca, destValue , lca_to_des);

        string result = "";

        for(int i=0;i<lca_to_src.size();i++) result+="U";

        result+=lca_to_des;

        return result;
        
    }
};