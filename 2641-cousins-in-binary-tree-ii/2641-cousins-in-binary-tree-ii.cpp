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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        //root -> val = 0;
        vector<int> level_sum;

        while(!q.empty()){
            int n = q.size();
            int sum=0;
            
            for(int i=0; i<n ;i++){
                TreeNode* front = q.front();
                sum += front->val;
                q.pop();

                if(front -> left){
                    q.push(front->left);
                }
                if(front -> right){
                    q.push(front->right);
                }
            }
            level_sum.push_back(sum);
        }

        queue<pair<TreeNode*,int>> pq;
        pq.push({root ,root->val});

        int index = 0;
        while(!pq.empty()){
            int n = pq.size();
            
            for(int i=0; i<n ;i++){
                auto front = pq.front();
                front.first -> val = level_sum[index] - front.second;
                pq.pop();

                int child_sum = 0;
                if(front.first -> left){
                    child_sum += (front.first -> left -> val);
                }
                if(front.first -> right){
                    child_sum += (front.first -> right -> val);
                }

                if(front.first -> left){
                    pq.push({front.first->left ,child_sum});
                }
                if(front.first -> right){
                    pq.push({front.first->right ,child_sum});
                }
            }
            index++;
        }
        return root;
    }
};