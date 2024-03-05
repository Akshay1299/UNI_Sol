class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r && s[l] == s[r]) {
            char tempL = s[l];
            while (tempL == s[l])
                l++;

            if (l >= r)
                return 0;
            
            char tempR = s[r];
            while (tempR == s[r])
                r--;
        }
        return r - l + 1;
    }
};