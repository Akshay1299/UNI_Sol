class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> distinctFromLeft(n);
        vector<int> leftFound(26, 0);
        vector<int> distinctFromRight(n);
        vector<int> rightFound(26, 0);
        
        int count1 = 0;
        for(int i = 0; i < n; i++)
        {
            if(leftFound[s[i] - 'a'] == 0)
            {
                count1++;
                leftFound[s[i] - 'a'] = 1;
            }
            distinctFromLeft[i] = count1;

        }
        
        int count2 = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(rightFound[s[i] - 'a'] == 0)
            {
                count2++;
                rightFound[s[i] - 'a'] = 1;
            }
            distinctFromRight[i] = count2;
        }
        
        int ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(distinctFromLeft[i] == distinctFromRight[i + 1])
            ans++;
        }        
        return ans;
    }
};