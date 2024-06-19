class Solution {
public:
bool isPossible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); 
    int cnt = 0;
    int noOfB = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val =1ll*m * 1ll*k;
        int n = bloomDay.size();

        if(n<val) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low=mini,high=maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(bloomDay,mid,m,k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};