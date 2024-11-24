class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& M) {
        long long sum = 0, min_elem = INT_MAX; bool is_neg_count_odd = false;
        for (auto r: M)
            for (auto c: r)
                is_neg_count_odd = c < 0 ? !is_neg_count_odd: is_neg_count_odd,
                sum += abs(c),
                min_elem = min(min_elem, (long long) abs(c));
        return sum - (is_neg_count_odd ? 2 * min_elem: 0);
    }
};