class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int qtr = n / 4;
        int cnt = 1;
        int ans = arr[0];
        for (int i = 1 ; i < n ; i++) {

            if ( ans == arr[i]) cnt++;
            else cnt = 1;
            
            if (cnt > qtr) return arr[i];
            
            ans = arr[i];
        }

        return ans;
    }
};