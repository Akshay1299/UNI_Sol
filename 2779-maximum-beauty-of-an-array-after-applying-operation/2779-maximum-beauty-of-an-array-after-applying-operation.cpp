class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxBeauty = 1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if (n == 1) return 1;
        
        vector<int> diff;
        for (int i = 1; i < n; i++) {
            diff.push_back(nums[i] - nums[i - 1]);
        }
        
        int count = 1;
        int prabh = 0;
        int i = 0, j = 0;

        while (j < n - 1) {
            if (diff[j] + prabh <= 2 * k) {
                prabh += diff[j];
                count++;
                j++;
            } else {
                maxBeauty = max(maxBeauty, count);
                prabh -= diff[i];
                i++;
                count--;
            }
        }
        maxBeauty = max(maxBeauty, count);

        return maxBeauty;
    }
};
