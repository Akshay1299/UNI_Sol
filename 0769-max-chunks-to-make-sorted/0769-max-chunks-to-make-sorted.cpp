class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int c = 0;
        int i = 0;
        while (i < n) {
            unordered_set<int> m;
            int y = 0;
            int z = c;
            while (i < n) {
                y = max(y, arr[i]);
                z = min(z, arr[i]);
                m.insert(arr[i]);
                if (y - z == (m.size() - 1)) {
                    break;
                }
                i++;
            }
            ans++;
            c=y+1;
            i++;
        }
        return ans;
    }
};