class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long currentSum = 0;
        int minLength = INT_MAX;
        deque<pair<long long, int>> dq;

        dq.push_back({0, -1});

        for (int i = 0; i < n; ++i) {
            currentSum += nums[i];

            while (!dq.empty() && currentSum - dq.front().first >= k) {
                minLength = min(minLength, i - dq.front().second);
                dq.pop_front();
            }

            while (!dq.empty() && currentSum <= dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({currentSum, i});
        }
        return minLength == INT_MAX ? -1 : minLength;
    }
};