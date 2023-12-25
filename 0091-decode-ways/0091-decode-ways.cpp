class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int n = s.size();
        vector<int> dp(n + 1);

        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            if (s[i - 2] == '1' or 
            (s[i - 2] == '2' and '0' <= s[i - 1] and s[i - 1] <= '6')) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
