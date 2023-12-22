class Solution {
public:
    int maxScore(string s) {

        int score = 0;
        int n = s.length();
        vector<int>zeroStartToI(n,0);
        vector<int>onceEndToI(n,0);

        if(s[0]=='0')
            zeroStartToI[0]=1;
        for(int i=1; i<n; i++){
            if(s[i]=='0')
                zeroStartToI[i]=zeroStartToI[i-1]+1;
            else
                zeroStartToI[i]=zeroStartToI[i-1];
        }

        if(s[n-1]=='1')
           onceEndToI[n-1]=1;
        for(int i=n-2; i>=0; i--){
            if(s[i]=='1')
                onceEndToI[i]=onceEndToI[i+1]+1;
            else
                onceEndToI[i]=onceEndToI[i+1];
        } 
        for(int i=0; i<n-1; i++){
            score = max(score,zeroStartToI[i]+onceEndToI[i+1]);
        }
        return score;
    }
};