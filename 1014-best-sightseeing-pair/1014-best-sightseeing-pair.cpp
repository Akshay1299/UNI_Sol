class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int n=v.size();
        int mx=v[0];
        int ans=0;
        for(int i=1;i<n;i++)
        {
            mx--;
            ans=max(ans,v[i]+mx);
            mx=max(mx,v[i]);
        }
        return ans;
    }
};