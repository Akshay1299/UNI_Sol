class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
    void f(int i,int j,bool & check, vector<vector<bool>>&vis, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(i<0 ||i>=grid1.size() || j<0 || j>=grid1[0].size() || vis[i][j] || !grid2[i][j])return ;

        if(!grid1[i][j])check=false;
     vis[i][j]=true;
     
    for(int k=0;k<4;k++){
        int x=dx[k]+i;
        int y=dy[k]+j;
      
        f(x,y,check,vis,grid1,grid2);
    }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        int n=grid1.size();
        int m=grid1[0].size();
        vector<vector<bool>> vis (n,vector<bool>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]){
                    bool check=true;
                    f(i,j,check,vis,grid1,grid2);
                     if(check)ans++;
                    
                }
            }
        }
        return ans;
    }
};