class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n=0, p=0;
        while(n<nums.size() && p<nums.size()){
            while(nums[n] >= 0) n++;
            while(nums[p] < 0) p++;
            ans.push_back(nums[p++]);
            ans.push_back(nums[n++]);
        }

        return ans;
    }
};