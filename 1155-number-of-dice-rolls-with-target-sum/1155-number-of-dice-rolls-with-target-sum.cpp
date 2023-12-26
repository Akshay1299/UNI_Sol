class Solution {
public:
    int mod=1e9+7;

    int rec(int level,int k,int sum,vector<vector<int>>&dp){
        if(level==0) return sum==0;
        if(sum<0) return 0;

        if(dp[level][sum]!=-1) return dp[level][sum];

        int ans=0;
        for(int i=1;i<=k;i++){
            if(sum+level<i) break;
            ans+=rec(level-1,k,sum-i,dp);
            ans%=mod;
        }

        return dp[level][sum]=ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return rec(n,k,target,dp);
    }
};