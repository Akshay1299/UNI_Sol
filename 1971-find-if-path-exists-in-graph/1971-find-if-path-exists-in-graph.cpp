class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int>mp[n];
            for(int i = 0; i < edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
            vector<bool> visited(n+1,false);
            queue<int>q;
            q.push(source);
            visited[source]=true;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(auto i :mp[u])
                {
                    if(visited[i]==false)
                    {
                        visited[i]=true;
                        q.push(i);
                    }
                }
                if(visited[destination])
                return visited[destination];
            }
            return visited[destination];    
    }
};