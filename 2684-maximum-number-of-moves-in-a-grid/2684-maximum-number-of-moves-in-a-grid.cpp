class Solution {
public:
    int maxMoves(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1));
        int ans=0;
        for (int j=1; j<m; ++j){
            for (int i=0; i<n; ++i){
                vector<int> v;
                if (g[i][j]>g[i][j-1]) v.push_back(dp[i][j-1]);
                if (i>0 && g[i][j]>g[i-1][j-1]) v.push_back(dp[i-1][j-1]);
                if (i<n-1 && g[i][j]>g[i+1][j-1]) v.push_back(dp[i+1][j-1]);
                if (v.empty()) dp[i][j]=0;
                else {
                    int mx=*max_element(v.begin(),v.end());
                    if (mx==0) dp[i][j]=0;
                    else dp[i][j]=mx+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        if (ans>0) ans--;
        return ans;
    }
};