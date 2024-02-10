class Solution {
public: 

    int dp[20001];

    int f(int index, vector<int>& nums, unordered_map<int, int>& mp){
        if(index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int ans = f(index + 1, nums, mp);
        int it = upper_bound(nums.begin(), nums.end(), nums[index] + 1) - nums.begin();
        ans = max(ans, nums[index]*mp[nums[index]] + f(it, nums, mp));
        return dp[index] = ans;
    }

    int deleteAndEarn(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(auto&i:nums) mp[i]++;
        return f(0, nums, mp);
    }
};