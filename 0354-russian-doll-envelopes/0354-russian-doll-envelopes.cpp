class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),[&](vector<int> &a, vector<int> &b)
        {
            if(a[0] == b[0])
            {
                return a[1] > b[1]; 
            }
            return a[0] < b[0];
        });
        vector<int> height;
        for(auto it : e)
        {
            height.push_back(it[1]);
        }
        int n = e.size();
        vector<int> tails;
        for(int i = 0; i < n; i++)
        {
            int ind = lower_bound(tails.begin(),tails.end(),height[i]) - tails.begin();
            if(ind == tails.size())
            {
                tails.push_back(height[i]);
            }
            else
            {
                tails[ind] = height[i];
            }
        }
        return tails.size();
    }
};