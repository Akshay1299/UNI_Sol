class Solution {
public:
    bool canPermute(int start, int curr, vector<int> &nums){
        for (int i=start; i<curr; ++i){
            if (nums[i]==nums[curr]) return false;
        }
        return true;
    }
    void rPermute(int ind, vector<int> &nums, vector<vector<int>> &ans){
        if (ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind; i<nums.size(); ++i){
            if (i>ind && !canPermute(ind,i,nums)) continue;
            swap(nums[ind],nums[i]);
            rPermute(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        rPermute(0,nums,ans);
        return ans;
    }
};