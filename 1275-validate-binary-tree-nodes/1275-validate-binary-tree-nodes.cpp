class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,bool>mp;
        vector<bool>vis(n,false);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                 q.push(i);
                 while(!q.empty()){
                       int x=q.front();
                       q.pop();
                       if(vis[x] && mp[x]){
                           mp.erase(x);
                           continue;
                       }
                       if(vis[x])return false;
                       if(leftChild[x]!=-1)q.push(leftChild[x]);
                       if(rightChild[x]!=-1)q.push(rightChild[x]);
                       vis[x]=true;

                 }
                 mp[i]=true; 
              }
        }
        return mp.size()==1;
    }
};