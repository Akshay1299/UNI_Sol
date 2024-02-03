class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector<int> memo(arr.size(), -1);
    return max_sum_after_partitioning(arr, memo, k);
}

int max_sum_after_partitioning(const vector<int>& arr, vector<int>& memo, int k, int i=0) {
    if(i == arr.size()) {
        return 0;
    } else {
        auto& cache = memo[i];
        if(cache == -1) {
            int maxsum = 0;
            for(int j = i, maxval = 0; j < min<int>(i + k, arr.size()); ++j) {
                maxval = max(maxval, arr[j]);
                maxsum = max(maxsum, maxval*(j+1-i) 
                            + max_sum_after_partitioning(arr, memo, k, j+1));
            }
            cache = maxsum;
        }
        return cache;
    }
}
};