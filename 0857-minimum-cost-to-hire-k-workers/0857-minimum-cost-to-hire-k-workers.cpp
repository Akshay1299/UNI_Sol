class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        priority_queue<int> pq;
        vector<pair<double, int>> ratio;
        int n = quality.size();
        for (int i = 0; i < n; i++) {
            ratio.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        sort(ratio.begin(), ratio.end());
        int tQuality = 0, count = 0;
        double mini = numeric_limits<double>::max();
        for (auto& [r, q] : ratio) {
            tQuality += q;
            count++;
            pq.push(q);
            if (count == k) {
                count--;
                mini = min(mini, tQuality * r);
                tQuality -= pq.top();
                pq.pop();
            }
        }
        return mini;
    }
};