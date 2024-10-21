class Solution {
public:
    int maxUniqueSplit(string s) {
        const int n = s.size();
        unordered_set<string> dict;
        return maxUniqueSplit(s, 0, n, dict);
    }
    int maxUniqueSplit(const string& s, const int start, const int n, unordered_set<string>& dict)
    {
        if (n == start)
        {
            return dict.size();
        }
        int res = 0;
        for (int i = start; i < n; ++ i)
        {
            const string sub = s.substr(start, i - start + 1);
            if (dict.count(sub))
                continue;
            dict.insert(sub);
            res = max(res, maxUniqueSplit(s, i + 1, n, dict));
            dict.erase(sub);
        }
        return res;
    }
};