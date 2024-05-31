class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>mpp;
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        for(auto i:mpp)
        {
            if(i.second==1)
            result.push_back(i.first);
        }
        return result;


    }
};