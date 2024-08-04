class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> temp;
        int m = nums.size();
        for(int i = 0 ; i < m ; i++){
            int count = 0;
            for(int j = i ; j < m ; j++){
                count = count + nums[j];
                temp.push_back(count);
            }
        }
        sort(temp.begin() , temp.end());
        long long ans = 0;
        const int mod = 1e9 + 7;
        for(int i = left-1 ; i <= right-1 ; i++){
            ans = (ans + temp[i])%mod;
        }
        return ans;
    }
};