class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<int> maxVal(events.size());
        int val = 0;
        for (int i = events.size() - 1; i >= 0; --i) {
            val = max(val, events[i][2]);
            maxVal[i] = val;
        }
        int res = 0;
        for (int i = 0; i < events.size(); ++i) {
            int left = i + 1, right = events.size() - 1,
            nextEvent = events.size();
            while (left <= right) {
                int mid = (left + right) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextEvent = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            int currentSum = events[i][2] + (nextEvent < events.size() ? maxVal[nextEvent] : 0);
            res = max(res, currentSum);
        }
        return res;
    }
};