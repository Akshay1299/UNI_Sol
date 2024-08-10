class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        
        int n = 3*grid.size();
        vector<vector<bool>> map(n, vector<bool>(n, false));
        int i=0, j=0;
        for(auto row:grid) {
            j=0;
            for(int idx=0;idx<row.length();++idx,j=j+3) {
                if(row[idx] == ' ')
                    continue;
                if(row[idx] == '/') {
                    map[i][j+2] = true;
                    map[i+1][j+1] = true;
                    map[i+2][j] = true;
                } else if (row[idx] == '\\') {
                    map[i][j] = true;
                    map[i+1][j+1] = true;
                    map[i+2][j+2] = true;
                }
            }
            i=i+3;
        }

        int result = 0;

        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                if(!map[i][j]) {
                    dfs(i, j, n, map);
                    result++;
                }
            }
        }

        return result;
    }

    void dfs(int i, int j, int n, vector<vector<bool>> &map) {
        if(i<0||i>=n||j<0||j>=n||map[i][j])
            return;
        map[i][j] = true;
        dfs(i, j+1, n, map);
        dfs(i+1, j, n, map);
        dfs(i, j-1, n, map);
        dfs(i-1, j, n, map);
    }
};