class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        bool ok = true;
        for(int i=1;i<n;i++){
            if(arr[i-1] > arr[i]){
                ok  = false;
            }
        }

        if(ok) return 0;

        vector<int> forward(n,0),backward(n,0);

        for(int i=1;i<n;i++){

            if(arr[i-1] <= arr[i]) forward[i] = forward[i-1]+1; 
        }

        for(int i=n-2;i>=0;i--){
            if(arr[i] <= arr[i+1] ) backward[i] = backward[i+1] + 1;
        }

        int ans = n-1, l = 1, r =n-1;

        while(l <= r){

            int mid = l + (r-l)/2;

            bool ok = false;

            for(int i=0;i<=n-mid;i++){
                
                int x1 = false, x2 = false, p = i + mid-1;
                long long int t1 = 0, t2 = 1e10;
                if((i > 0 && forward[i-1] == i-1) || i == 0){                 
                    if(i > 0) t1 = arr[i-1];
                    x1 = true;
                }

                if((p < n-1 && p + 1 + backward[p+1] == n-1) || p == n-1){
                    if(p < n-1) t2 = arr[p+1];
                    x2 = true;
                }

                if(x1 && x2 && t1 <= t2)ok = true;

            }

            if(ok){
                ans = min(ans, mid);
                r = mid-1;
            }else{
                l = mid + 1;
            }

        }

        return ans;

    }
};