class Solution {
public:
    long long mod = 1e9+7, s[100005] = {1, 1, 2};
    int checkRecord(int n) {
        for(int i = 3; i <= n+1; ++i)
            s[i] = (s[i-1] + s[i-2] + s[i-3]) % mod;
        for(int i = 1; i <= n; ++i) 
            s[n+1] = (s[n+1] + s[i] * s[n-i+1]) % mod;
        return s[n+1];
    }
};