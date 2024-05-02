class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>m;
        int max_positive=-1;
        for(int i=0;i<nums.size();i++){
            int polaropposite = -1 * nums[i];

            if(m.find(polaropposite)!=m.end())max_positive=max(max_positive,abs(nums[i]));

            m[nums[i]]=i;
        }
        return max_positive;
    }
};