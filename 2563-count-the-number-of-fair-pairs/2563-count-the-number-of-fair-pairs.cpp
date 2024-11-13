class Solution {
public:
    int binarySearch(vector<int>& nums, long long lower, long long upper) {
        int start = 0;
        int end = nums.size()-1;
        int ans1 = -1;
        int ans2 = -1;
        while (start <= end) {
            int mid = start+(end-start)/2;
            if (nums[mid] >= lower && nums[mid] <= upper) {
                ans1 = mid;
                end = mid-1;
            } else if (nums[mid] >= lower && nums[mid] >= upper) {
                end = mid-1;
            } else start = mid+1;
        }
        start = 0;
        end = nums.size()-1;
        while (start <= end) {
            int mid = start+(end-start)/2;
            if (nums[mid] >= lower && nums[mid] <= upper) {
                ans2 = mid;
                start = mid+1;
            } else if (nums[mid] >= lower && nums[mid] >= upper) {
                end = mid-1;
            } else start = mid+1;
        } 
        if (ans1 == -1 || ans2 == -1) {
            return 0;
        } return ans2-ans1+1;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        vector<int> prev;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) {
            int cnt = binarySearch(prev, lower-nums[i], upper-nums[i]);
            ans += cnt;
            prev.push_back(nums[i]);
        } return ans;
    }
};