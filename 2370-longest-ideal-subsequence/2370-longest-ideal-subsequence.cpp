class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        int ans = 0;
        for(int i=0; i<s.size(); ++i) {
            int x = s[i]-'a', curr = 1;
            for(int j=0; j<26; ++j) {
                if(abs(j-x)<=k) curr=max(curr, dp[j]+1);
            }
            dp[x] = curr;
            ans = max(ans, curr);
        }
     return ans;
    }
};