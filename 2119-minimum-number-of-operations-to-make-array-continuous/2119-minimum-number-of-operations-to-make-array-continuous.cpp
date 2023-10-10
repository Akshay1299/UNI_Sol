class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int k = unique(nums.begin(), nums.end()) - nums.begin();
        
        int result = INT_MAX;
        for (int l = 0, r = 0; r < k; r++) {
            while ((l < r) && ((nums[l] + n - 1) < nums[r])) l++;
            result = min(result, n - (r - l + 1));
        }
        return result;
    }
};