class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<long long> pre(n+1);
        for(int i=0;i<n;i++) {
            pre[i+1] = pre[i] ^ arr[i];
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int k=i+1;k<n;k++) {
                for(int j=i+1;j<=k;j++) {
                    long long a = pre[j] ^ pre[i];
                    long long b = pre[k+1] ^ pre[j];
                    if(a == b) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};