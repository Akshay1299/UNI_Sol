class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return prices;
        vector<int> ans(n);
        ans[n-1] = prices[n-1];
        stack<int> st;
        st.push(prices[n-1]);
        for(int i=n-2; i>=0; i--){
            while(st.size() && st.top() > prices[i]) st.pop();
            if(st.size()) ans[i] = prices[i] - st.top();
            else ans[i] = prices[i];
            st.push(prices[i]);
        }
        return ans;
    }
};