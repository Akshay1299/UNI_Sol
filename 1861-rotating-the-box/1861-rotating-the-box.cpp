class Solution {
public:
    vector<vector<char>> rotateClockwise(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> rotated(m, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotated[j][n - 1 - i] = box[i][j];
            }
        }
        return rotated;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> result = rotateClockwise(box);
        int n = result.size();
        int m = result[0].size();

        for (int j = 0; j < m; j++) {
            int k = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '*') {
                    k = i - 1; 
                } else if (result[i][j] == '#') {
                    result[i][j] = '.';
                    result[k][j] = '#';
                    k--;
                }
            }
        }
        return result;
    }
};