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
class Solution {// upvote if it helps 
public:
   map<int ,vector<int>>m;
   void build(TreeNode* root)
   {
       if(!root)
       return ;
       if(root->left)
       {
           m[root->val].push_back(root->left->val);
           m[root->left->val].push_back(root->val);
       }
       if(root->right)
       {
           m[root->val].push_back(root->right->val);
           m[root->right->val].push_back(root->val);
       }
       build(root->left);
       build(root->right);
   }
   int bfs(int s)
   {
       queue<pair<int,int>>q;
       int d=0;
       q.push({s,d});
       set<int>st;
       st.insert(s);
       while(!q.empty())
       {
          auto p=q.front();
          q.pop();
          int dist=p.second;
          s=p.first;
          for(auto i:m[s])
          {
              if(st.find(i)==st.end())
              {
                  st.insert(i);
                  q.push({i,dist+1});
                  d=max(d,dist+1);
              }
          }
       }
       return d;
   }
    int amountOfTime(TreeNode* root, int start) {
        if(!root)
        return 0;
        build(root);
        return bfs(start);
    }
};