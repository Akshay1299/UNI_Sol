class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        int ans = 0;
        bool isodd = false;
        vector<int> mpp(256, 0);
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }
        for (int i = 0; i < mpp.size(); i++) {
            if (mpp[i] % 2 == 0) {
                ans += mpp[i];
            } else {
                ans += mpp[i] - 1;
                isodd = true;
            }
        }
        if (isodd) {
            ans += 1;
        }
        return ans;
    }
};