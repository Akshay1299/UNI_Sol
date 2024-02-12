class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i: nums)
        {
             mp[i]++;
        }
        int ans=0;
        int freq=0;
        for(auto it: mp)
        {
            if(freq<it.second)
            {
                freq=it.second;
                ans=it.first;
            }

        }
        return ans;
    }
};