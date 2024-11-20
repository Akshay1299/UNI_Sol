class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> totalCount(3, 0);
        for (char c : s) {
            totalCount[c - 'a']++;
        }

        for (int count : totalCount) {
            if (count < k) return -1;
        }

        int n = s.size();
        int maxWindowLength = 0;
        vector<int> windowCount(3, 0);
        int left = 0;

        for (int right = 0; right < n; ++right) {
            windowCount[s[right] - 'a']++;

            while (windowCount[0] > totalCount[0] - k ||
                   windowCount[1] > totalCount[1] - k ||
                   windowCount[2] > totalCount[2] - k) {
                windowCount[s[left] - 'a']--;
                left++;
            }

            maxWindowLength = max(maxWindowLength, right - left + 1);
        }

        return n - maxWindowLength;
    }
};