class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        // {blocks removed, {x, y}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        dist[0][0] = 0;
        
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int blocks = node.first;
            int x = node.second.first;
            int y = node.second.second;
            
            if (x == n - 1 && y == m - 1) return blocks;
            
            if (dist[x][y] < blocks) continue;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                
                int newBlocks = blocks + (grid[nx][ny] == 1 ? 1 : 0);
                
                if (newBlocks < dist[nx][ny]) {
                    dist[nx][ny] = newBlocks;
                    pq.push({newBlocks, {nx, ny}});
                }
            }
        }
        
        return -1; // If unreachable, return -1
    }
};