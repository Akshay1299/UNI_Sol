class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        long long int ans = 0, sum = 0;
        int i = 0, j = 0;
        while ( j < nums.size() ) {
            while (i <= m[nums[j]] && m[nums[j]] > 0) {
                sum -= nums[m[nums[i]] - 1];
                m[nums[i]] = -1;
                i++;
            }
            m[nums[j]] = j + 1;
            sum += nums[j];
            if ((j - i + 1) == k) {
                ans = max(ans, sum);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return ans;
    }
};