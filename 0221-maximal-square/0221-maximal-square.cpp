class Solution {
public:
    int ans1=0;  
    int helper(vector<vector<char>>& matrix,int i,int j,vector<vector<int>>& dp){
        if((i+1)>=matrix.size() || (j+1) >= matrix[0].size()){
            if(matrix[i][j]=='0'){
                dp[i][j]=0;
                return 0;
            }
            else{
                dp[i][j]=1;
                ans1=max(ans1,dp[i][j]);
                return 1;
            }
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(matrix[i][j]=='0'){
            dp[i][j]=0;
            return 0;
        }
        int ans=1;
        int rightans=helper(matrix,i,j+1,dp);
        int downans=helper(matrix,i+1,j,dp);
        int diagans=helper(matrix,i+1,j+1,dp);
        if(rightans!=0 && downans!=0 && diagans!=0){
            int rightmin=min(rightans,diagans);
            int downmin=min(downans,diagans);
            int mini=min(rightmin,downmin);
            ans=1+mini;
        }
        dp[i][j]=ans;
        ans1=max(ans1,dp[i][j]);
        return ans;

        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                    continue;
                }
                if(dp[i][j]==-1){
                    dp[i][j]=helper(matrix,i,j,dp);
                    ans1=max(ans1,dp[i][j]);
                }
            }
        }
        
        return ans1*ans1;
    }
};