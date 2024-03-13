class Solution {
public:
    int pivotInteger(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int Sum = n * (n+1)/2;
        
        int s = 1;
        int end = n;

        while(s <= end){
            int mid = s+(end-s)/2;

            int l_Sum = mid * (mid+1)/2;

            if(Sum - l_Sum + mid == l_Sum){
                return mid;
            }

            else if(Sum - l_Sum + mid > l_Sum){
                s = mid + 1;
            }

            else {
                end = mid - 1;
            }
        }
        return -1;

    }
};