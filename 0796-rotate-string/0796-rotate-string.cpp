class Solution {
public:
    bool rotateString(string s, string goal) {
        const string str = s + s;
        const int n = (int) s.size();
        if (goal.size() != n) {
            return false;
        }
        std::size_t pos = str.find(goal);
        if (pos == string::npos) {
            return false;
        }
        return true;
    }
};
