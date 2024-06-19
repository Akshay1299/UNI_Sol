class Solution {
public:
    void combination(vector<vector<int>>& v, vector<int>& s, vector<int>& c,
                     int i, int t, int sum) {
        if (sum == t) {
            v.push_back(s);
            return;
        }
        if (sum>t) {
            return;
        }
        for (int k = i; k < c.size(); k++) {
            if(k>i && c[k]==c[k-1]){
                continue;
            }
            s.push_back(c[k]);
            sum+= c[k];
            combination(v, s, c, k + 1, t,sum);
            s.pop_back();
            t += c[k];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>> v;
        vector<int> s;
        sort(c.begin(),c.end());
        combination(v, s, c, 0, t,0);
        return v;
    }
};