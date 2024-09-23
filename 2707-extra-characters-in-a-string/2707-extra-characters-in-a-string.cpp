class Solution {
public:
    int dp[52];
    int fn(int i,string &s,set<string>&st){
        
        if(i==s.length())return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        int tk=INT_MAX;
        for(int k=i;k<s.length();k++){
            
            string temp=s.substr(i,k-i+1);
            if(st.find(temp)!=st.end()){
                tk=min(tk,fn(k+1,s,st));
            }
            else{
                tk=min(tk,k-i+1+fn(k+1,s,st));
            }
        }
        return dp[i]=tk;
    }
    
    int minExtraChar(string s, vector<string>& dis) {
        
        memset(dp,-1,sizeof(dp));
        set<string>st(begin(dis),end(dis));
        return fn(0,s,st);
    }
};