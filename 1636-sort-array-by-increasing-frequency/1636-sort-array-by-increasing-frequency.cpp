class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> m;
        for (int x : nums) m[x]++;
        
        auto compare = [&m](int a, int b) {
            if (m[a] == m[b]) return a > b;
            return m[a] < m[b]; 
        };
        
        sort(nums.begin(), nums.end(), compare);
        return nums;
    }
};