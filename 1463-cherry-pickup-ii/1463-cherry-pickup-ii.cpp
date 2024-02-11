class Solution {
public:
int dp[70][70][70];
    int fun(int j1,int j2,int i,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(j1<0 || j2<0 || j1==n || j2==n) return -1e8;
        if(i==m) return 0;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=0;
        int a=grid[i][j1], b=grid[i][j2];
        ans+=grid[i][j1];
        grid[i][j1]=0;
        ans+=grid[i][j2];
        grid[i][j2]=0;
        int arr[3]={-1,0,1};
        int v=0;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                v=max(v,fun(j1+arr[k],j2+arr[l],i+1,grid));
            }
        }
        grid[i][j1]=a, grid[i][j2]=b;
        return dp[i][j1][j2]=ans+v;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return fun(0,n-1,0,grid);
    }
};