class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=0;i<s.size()-1;i++){
            char ch=s[i];
            char ch1=s[i+1];
            int z=ch-ch1;
            int toa=abs(z);
            sum+=toa;
        }
        return sum;
    }
};