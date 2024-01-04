class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        for (auto i : nums) {
            mp[i]++;
        }
        for (auto i : mp) {
            if (i.second == 1) {
                return -1;
            }
            else if (i.second % 3 == 0) {
                res += i.second / 3;
            }
            else {
                res += i.second / 3 + 1;
            }
        }
        return res;
    }
};