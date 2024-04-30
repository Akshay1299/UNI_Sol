class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long result = 0;
        int mask = 0;

        vector<long> count(1024);
        count[0] = 1;

        for (const char& c : word) {
            mask ^= 1 << (c - 'a');
            result += count[mask];

            for (int i = 0; i < 10; ++i) {
                result += count[mask ^ (1 << i)];
            }

            ++count[mask];
        }

        return result;
    }
};