class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(k+1, vector<int>(n));
        for(int i=1; i<=k; i++) {
            int mxVal = -a[0];
            for(int j=1; j<n; j++){
                dp[i][j] = max(dp[i][j-1], a[j]+mxVal);
                mxVal = max(mxVal, dp[i-1][j-1]-a[j]);
            }
        }
        return dp[k][n-1];
    }
};