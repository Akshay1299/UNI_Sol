class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> ans;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            } else if (logs[i] != "./") {
                ans.push_back(logs[i]);
            }
        }
        return ans.size();
    }
};