class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(degree[i]==1){
                q.push(i);
            }
        }

        while(n>2){
            int size = q.size();
            n=n-size;
            while(size--){
                int x = q.front();
                q.pop();
                for(int it: adj[x]){
                    degree[it]--;
                    if(degree[it]==1){
                        q.push(it);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};