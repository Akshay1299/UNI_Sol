class Solution {
public:
    int m, n;
    std::vector<std::pair<int, int>> directions{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void DFS(int row, int col, std::vector<std::vector<int>>& grid, int sum,
             int& result) {
        if (row >= m || row < 0 || col >= n || col < 0 || grid[row][col] == 0) {
            result = std::max(result, sum);
            return;
        }
        int curr = grid[row][col];
        grid[row][col] = 0;
        sum += curr;
        for (auto d : directions)
            DFS(row + d.first, col + d.second, grid, sum, result);
        grid[row][col] = curr;
    }
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                DFS(i, j, grid, 0, result);
            }
        }
        return result;
    }
};