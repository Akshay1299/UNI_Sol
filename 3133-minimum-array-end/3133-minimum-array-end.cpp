class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> v;
        long long curr = x;
        long long calc = n - 1;

        for (int i = 0; i < 32; i++) {
            if (!((1 << i) & x)) {
                v.push_back(i);
            }
        }

        for (int i = 32; i < 64; i++) {
            v.push_back(i);
        }

        for (int i = 0; calc > 0; i++, calc >>= 1) {
            curr += (calc & 1) << v[i];
        }

        return curr;
    }
};
