class Solution {
public:
    
    int solve(vector<vector<int>>& grid){
        int ans = 50;
        bool check = true;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0){
                    check = false;
                    for(int k=0;k<3;k++){
                        for(int l=0;l<3;l++){
                            if(grid[k][l]>1){
                                grid[k][l]--;
                                grid[i][j] = 1;
                                ans = min(ans, (abs(i-k)+abs(j-l)) + solve(grid));
                                grid[i][j] = 0;
                                grid[k][l]++;
                            }
                        }
                    }
                }
            }
        }
        if(check) return 0;
        return ans;
    }
    
    int minimumMoves(vector<vector<int>>& grid){
        return solve(grid);
    }
};