class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        for (int i = 0; i < pow(2, nums.size()); i++) {
            int pos = 0;
            int data = i;
            while (data != 0) {
                if (data & 1) {
                    v.push_back(nums[pos]);
                }
                pos++;
                data = data >> 1;
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};