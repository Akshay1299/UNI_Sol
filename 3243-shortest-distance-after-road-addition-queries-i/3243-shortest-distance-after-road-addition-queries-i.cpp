class Solution {

    int bfs(int n,vector<vector<int>> &g){
        queue<int> q;
        vector<int> dist(n,INT_MAX);
        q.push(0);
        dist[0]=0;
        while(!q.empty()){
            int curr= q.front();
            q.pop();
            for(int node: g[curr]){
                if(dist[node]>dist[curr]+1){
                    dist[node]=dist[curr]+1;
                    q.push(node);
                }
            }
        }
        return dist[n-1];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> roads(n);
        for(int i=1;i<n;i++){
            roads[i-1].push_back(i);
        }
        vector<int> res;
        for(auto &query:queries){
            roads[query[0]].push_back(query[1]);
            res.push_back(bfs(n,roads));
        }
        return res;
    }
};