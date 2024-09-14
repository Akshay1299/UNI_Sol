class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int maxLength = 0;
        int i = 0;
        while(i<n){
            if(nums[i]>=maxi){
                int left = i;
                while(i<n-1 && nums[i]==nums[i+1])i++;
                if(nums[i]>maxi)maxLength = i-left+1;
                else maxLength = max(maxLength,i-left+1);
                maxi = nums[i];
            }
            i++;
        }
        return maxLength;
    }
};