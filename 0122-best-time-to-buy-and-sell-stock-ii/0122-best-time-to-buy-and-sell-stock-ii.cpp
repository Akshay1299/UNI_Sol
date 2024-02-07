class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int ans = 0;
        for (int index = 1; index < prices.size(); ++index) {
            int profit = prices[index] - prices[index - 1];
            if (profit > 0) {
                ans += profit;
            }
        }
        return ans;
    }
};