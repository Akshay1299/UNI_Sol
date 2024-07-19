class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> minRow(matrix.size(), INT_MAX);
        vector<int> maxCol(matrix[0].size(), INT_MIN);

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] < minRow[i]) {
                    minRow[i] = matrix[i][j];
                }
            }
        }

        for (int j = 0; j < matrix[0].size(); ++j) {
            for (int i = 0; i < matrix.size(); ++i) {
                if (matrix[i][j] > maxCol[j]) {
                    maxCol[j] = matrix[i][j];
                }
            }
        }

        vector<int> lucky;
        for (int i = 0; i < minRow.size(); ++i) {
            if (find(maxCol.begin(), maxCol.end(), minRow[i]) != maxCol.end()) {
                lucky.push_back(minRow[i]);
            }
        }

        return lucky;
    }
};