class Solution {
public:
    int solve(string& ring, string& key, int ptr, int i, vector<vector<int>>& dp){
        int n = ring.size(), m = key.size();
        if(i >= m) return 0;
        if(dp[i][ptr] != -1) return dp[i][ptr];
        int steps = 1e9;
        for(int j = 0 ; j < n ; j++){
            if(ring[j] == key[i]){
                steps = min(steps, min(abs(j-ptr), n-abs(j-ptr))+1+solve(ring, key, j, i+1, dp));
            }
        }
        return dp[i][ptr] = steps;
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int ptr = 0, index = 0;
        return solve(ring, key, ptr, index, dp);
    }
};