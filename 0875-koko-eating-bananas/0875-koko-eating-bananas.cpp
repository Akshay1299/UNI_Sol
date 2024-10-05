class Solution {
public:
    bool check(vector<int>& piles, int h, int mid){
        double sum = 0;
        int n = piles.size();
        for (int i = 0; i < n; ++i){
            sum += ceil((double)piles[i] / mid);
        }
        return sum <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;
        while(left <= right){
            int mid = (left + right) / 2;
            if (check(piles, h, mid)){
                ans = mid;
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return ans;
    }
};