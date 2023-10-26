class Solution {
public:
    int subarray(vector<int>& nums, int k){
        map<int,int>mp;
        int i=0,j=0,n=nums.size();
        int count=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray(nums,k)-subarray(nums,k-1);
    }
};