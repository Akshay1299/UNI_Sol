class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 0, p3 = 0, p5 = 0;
        vector<int>vec(n);
        vec[0] = 1;
        for(int i = 1; i<n; i++)
        {
            vec[i] = min({vec[p2]*2, vec[p3]*3, vec[p5]*5});

            if(vec[i] == vec[p2]*2) p2++;
            if(vec[i] == vec[p3]*3) p3++;
            if(vec[i] == vec[p5]*5) p5++;
        }

        for(auto it: vec) cout<<it<<" ";
        return vec[n-1];
    }
};
