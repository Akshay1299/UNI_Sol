class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>temp;
       vector<vector<int>>ans;
        if(root==NULL) return temp;
        q.push(root);
        while(q.empty()!=true)
        {   vector<int>v;
            int n=q.size();
            for(int i=0;i<n;i++)
            {   TreeNode* t=q.front();q.pop();
                v.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(v);
         int ma=v[0];
         for(int i=1;i<v.size();i++)
             ma=max(ma,v[i]);
         temp.push_back(ma);
        }
        return temp;
    }
};
// class Solution {
//     void dfs(TreeNode* cur, vector<int>& res, int height) {
//         if (!cur)
//             return;
//         if (height >= res.size())
//             res.push_back(cur->val);
//         else
//             res[height] = max(res[height], cur->val);
//         dfs(cur->left, res, height + 1);
//         dfs(cur->right, res, height + 1);
//     }
// public:
//     vector<int> largestValues(TreeNode* root) {
//         vector<int> res;
//         int height = 0;
//         dfs(root, res, height);
//         return res;
//     }
// };