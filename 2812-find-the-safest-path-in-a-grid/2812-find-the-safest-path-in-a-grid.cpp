class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int, pair<int, int>>> pendingNodes;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                pendingNodes.push({0, {i, j}});
            }
        }
          for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
             grid[i][j]=INT_MAX;
                else grid[i][j]=0;
            }
        }
        while(!pendingNodes.empty())
        {
            int distance=pendingNodes.front().first;
            int x=pendingNodes.front().second.first;
            int y=pendingNodes.front().second.second;
            pendingNodes.pop();
            int delx[]={-1, 0, 1, 0};
            int dely[]={0, 1, 0, -1};
            for(int i=0;i<4;i++)
            {
                int newx=x+delx[i];
                int newy=y+dely[i];
                if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]>(distance+1))
                {
                    grid[newx][newy]=distance+1;
                    pendingNodes.push({grid[newx][newy], {newx, newy}});
                }
            }
        }
  
        vector<vector<int>> maxDist(n, vector<int>(m, INT_MIN));
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({grid[0][0], {0, 0}});
        maxDist[0][0]=grid[0][0];
        while(!pq.empty())
        {
            int maxDistance=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            if(x==(n-1) && y==(m-1))
                return maxDistance;
            pq.pop();
            int delx[]={-1, 0, 1, 0};
            int dely[]={0, 1, 0, -1};
            for(int i=0;i<4;i++)
            {
                int newx=x+delx[i];
                int newy=y+dely[i];
                if(newx>=0 && newy>=0 && newx<n && newy<m && min(maxDistance, grid[newx][newy])>maxDist[newx][newy])
                {
                    maxDist[newx][newy]=min(maxDistance, grid[newx][newy]);
                    pq.push({maxDist[newx][newy], {newx, newy}});
                }
            }
        }
    
        return maxDist[n-1][m-1];
        
    }
};