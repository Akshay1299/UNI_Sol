class Solution {
    public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int> count(26);

        for (char c : word) count[c - 'a']++;
        sort(count.begin(), count.end(), greater<>());

        for (int i = 0; i < 26; i++) ans += count[i] * (i / 8 + 1);

        return ans;
    }
};