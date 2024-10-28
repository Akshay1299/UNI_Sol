class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        vector<bool> isVisited(100000 + 1, false);
        vector<bool> isPresent(100000 + 1, false);
        for (int x : nums) {
            isPresent[x] = true;
        }
        int maxLength = -1;
        for (long long x : nums) {
            int currentLength = 1;
            if (isVisited[x])
                continue;
            isVisited[x] = true;
            while (x*x <= 100000 && isPresent[x * x]) {
                x = x * x;
                currentLength++;
                isVisited[x] = true;
            }
            if (currentLength > 1)
                maxLength = max(maxLength, currentLength);
        }
        return maxLength;
    }
};