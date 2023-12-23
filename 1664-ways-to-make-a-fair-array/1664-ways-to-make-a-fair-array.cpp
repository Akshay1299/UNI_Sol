class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        vector<int> even(n+1, 0);
        vector<int> odd(n+1, 0);

        if (n%2 == 0) odd[n-1] = nums[n-1];
        else even[n-1] = nums[n-1];

        for (int i= n-2; i>=0; i--) {
            if (i%2 == 0) {
                odd[i] = odd[i+1];
                even[i] = even[i+1] + nums[i];
            }
            else {
                odd[i] = nums[i] + odd[i+1];
                even[i] = even[i+1];
            }
        }

        for (int i=0; i<n; i++) {
            int odd_sum = odd[0] - odd[i] + even[i+1];
            int even_sum = even[0] - even[i] + odd[i+1];
            if (odd_sum == even_sum) ans++;
        }

        return ans;
    }
};