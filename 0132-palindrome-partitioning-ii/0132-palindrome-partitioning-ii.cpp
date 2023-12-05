class Solution {
public:
   vector<int> dp;

    bool palin(string &s,int st,int en){
        while(st<=en){
            if(s[st]!=s[en])
                return 0;
            st++;
            en--;
        }
        return 1;
    }

    int func(string &s,int i,int j){
        if(i>=j) return 0;
        if(palin(s,i,j)) return 0;

        if(dp[i]!=-1)    return dp[i];


        int mx=INT_MAX;
        for(int k=i;k<j;k++){
            if(palin(s,i,k)){
            int c2=(dp[k+1]!=-1)?dp[k+1]:func(s,k+1,j);
            mx=min(mx,c2+1);
            }

        }
        return dp[i]=mx;
    }

    int minCut(string s) {
        int n=s.size();
        dp.resize(n+2,-1);
       
        return func(s,0,n-1);        
    }
};