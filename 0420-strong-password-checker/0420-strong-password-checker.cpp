class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        vector<int> p(4);
        vector<int> cnts = {1};
        for (auto i = 0; i < n; ++i) {
            if (isdigit(password[i]))
                p[0] = 1;
            else if (islower(password[i]))
                p[1] = 1;
            else if (isupper(password[i]))
                p[2] = 1;
            else
                p[3] = 1;
        }
        for (auto i = 1; i < n; ++i) {
            if (password[i] == password[i - 1])
                ++cnts.back();
            else {
                if (cnts.back() < 3)
                    cnts.pop_back();
                cnts.push_back(1);
            }
        }
        if (cnts.back() < 3)
            cnts.pop_back();
        auto f = [](vector<int>& c) {
            int res(0);
            for (auto a : c) res += a / 3;
            return res;
        };

        int tmp(3);
        for (auto i = 0; i < 3; ++i) tmp -= p[i];
        if (n <= 5) {
            return max(6 - n, tmp);
        }
        if (n <= 20) {
            return max(f(cnts), tmp);
        }

        int z = n - 20;
        int res = 0;
        while (z) {
            bool t = true;
            for (auto& x : cnts)
                if (x > 2 && x % 3 == 0) {
                    --x;
                    ++res;
                    --z;
                    t = false;
                    break;
                }
            if (t)
                for (auto& x : cnts)
                    if (x > 2 && x % 3 == 1) {
                        --x;
                        ++res;
                        --z;
                        t = false;
                        break;
                    }
            if (t)
                for (auto& x : cnts)
                    if (x > 2 && x % 3 == 2) {
                        --x;
                        ++res;
                        --z;
                        t = false;
                        break;
                    }
            if (t) break;
        }
        return res + max(f(cnts), tmp) + z;
    }
};