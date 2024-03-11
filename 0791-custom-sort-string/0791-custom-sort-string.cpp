#include <vector>

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> char_count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            char_count[s[i] - 'a']++;
        }
        string result(s.length(), ' ');
        int result_index = 0;
        for (int i = 0; i < order.length(); i++) {
            char current_char = order[i];
            while (char_count[current_char - 'a'] > 0) {
                result[result_index++] = current_char;
                char_count[current_char - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (char_count[i] > 0) {
                result[result_index++] = (char) (i + 'a');
                char_count[i]--;
            }
        }
        return result;
    }
};