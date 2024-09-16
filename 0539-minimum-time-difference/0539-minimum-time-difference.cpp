class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for(auto time : timePoints){
            int colonPos = time.find(":");
            int hrs = stoi(time.substr(0, colonPos));
            int mins = stoi(time.substr(colonPos + 1));
            v.push_back(hrs * 60 + mins);
        }
        sort(v.begin(), v.end());
        int res = INT_MAX;
        int n = v.size();
        for(int i = 1; i<n; i++){
            res = min(res, v[i] - v[i-1]);
        }

        res = min(res, 1440-v[n-1] + v[0]);
        return res;
    }
};