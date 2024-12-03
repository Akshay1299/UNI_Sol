class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        for (int idx = 0, spaceIdx = 0; idx < s.size(); ++idx) {
            if (spaceIdx < spaces.size() && idx == spaces[spaceIdx]) {
                result += ' ';
                ++spaceIdx;
            }
            result += s[idx];
        }
        return result;
    }
};