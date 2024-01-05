class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int length = 1;
        for(int i = 1; i<nums.size();i++)
        {
            if(temp.back() < nums[i])
            {
                temp.push_back(nums[i]);
                length++;
            }
            else
            {
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return length;
    }
};