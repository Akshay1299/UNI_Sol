class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        int minPos = -1;
        int maxPos = -1;
        int left = 0;
        int right = 0;
        long long ans = 0;
        
        for (right = 0; right < n; right++) {
            if (nums[right] < minK || nums[right] > maxK) {
                minPos = -1;
                maxPos = -1;
                left = right + 1;

                continue;
            }
            else {
                if (nums[right] == maxK) {
                    maxPos = right;
                }
                if (nums[right] == minK) {
                    minPos = right;
                }

                if (maxPos != -1 && minPos != -1) {
                    ans += (min(minPos, maxPos) - left + 1); 
                }
            }
        }

        return ans;
    }
};