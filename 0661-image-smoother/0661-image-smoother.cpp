class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> smoothimg(m, vector<int>(n, 0));
        int total = 0, count = 0;
        for (int r = 0; r < m; r++){
            for (int c = 0; c < n; c++){
                total = img[r][c];
                count = 1;
                if (r-1 >= 0 && c-1 >= 0){
                    total += img[r-1][c-1];
                    count += 1;
                }
                if (r-1 >= 0){
                    total += img[r-1][c];
                    count += 1;
                }
                if (c+1 < n && r-1 >= 0){
                    total += img[r-1][c+1];
                    count += 1;
                }
                if (c-1 >= 0){
                    total += img[r][c-1];
                    count += 1;
                }
                if (c+1 < n){
                    total += img[r][c+1];
                    count += 1;
                }
                if (r+1 < m && c-1 >= 0){
                    total += img[r+1][c-1];
                    count += 1;
                }
                if (r+1 < m){
                    total += img[r+1][c];
                    count += 1;
                }
                if (r+1 < m && c+1 < n){
                    total += img[r+1][c+1];
                    count += 1;
                }
                smoothimg[r][c] = total/count;
            }
        }
        return smoothimg;
    }
};