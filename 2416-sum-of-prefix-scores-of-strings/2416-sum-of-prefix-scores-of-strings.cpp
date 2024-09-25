class Solution {
public:
    const long long mod = 1e15 + 7;
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<long long,int>m1;
        long long pow[1001]={0};
        pow[0]=1;
        for(int i=1;i<=1000;i++)
            pow[i] = (pow[i-1]*31)%mod;
        for(string &word:words){
            long long val=0;
            for(int i=0;i<word.size();i++){
                val = (val + pow[1000-i]*(word[i]-'a'+1))%mod;
                m1[val]++;
            }
        }
        vector<int>sol;
        for(string &word:words){
            int c=0;
            long long val=0;
            for(int i=0;i<word.size();i++){
                val = (val + pow[1000-i]*(word[i]-'a'+1))%mod;
                c += m1[val];
            }
            sol.emplace_back(c);
        }
        return sol;
    }
};