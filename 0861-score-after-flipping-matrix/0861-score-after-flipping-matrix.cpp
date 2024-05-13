
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        for(int i = 0; i < r; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < c; j++) {
                    grid[i][j] == 0 ? grid[i][j] = 1 : grid[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < c; i++) {
            int count0 = 0;
            int count1 = 0;
            for(int j = 0; j < r; j++) {
                if(grid[j][i] == 0) {
                    count0++;
                } else {
                    count1++;
                }
            }

            if(count0 > count1) {
                for(int j = 0; j < r; j++) {
                    grid[j][i] == 0 ? grid[j][i] = 1 : grid[j][i] = 0;
                }
            }
        }
        int ans  = 0;
        for(int i = 0; i < r; i++) {
            int v = 0;
            for(int j = c-1; j >= 0; j--) {
                ans += grid[i][j] * pow(2,v);
                v++;
            }
        }

        return ans;
    }
};