class Solution {
public:
    int minimumDeletions(string s) {
        int deletions = 0;
        stack<char> stk;
        
        for (char c : s) {
            if (c == 'b') {
                stk.push(c);
            } else if (c == 'a') {
                if (!stk.empty()) {
                    deletions++;
                    stk.pop();
                }
            }
        }
        
        return deletions;
    }
};