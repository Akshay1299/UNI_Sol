class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),ans=INT_MAX;
        int min1=100,min2=100,id1=0,id2=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(row==0) break;
                if(col==id1) grid[row][col] += grid[row-1][id2];
                else grid[row][col] += grid[row-1][id1];
            }
            min1=100;
            min2=100;
            for(int col=0;col<n;col++){
                if(grid[row][col]<min2) {
                    min2=grid[row][col];
                    id2=col;
                }
                if(min2<min1) {
                    swap(min1,min2);
                    swap(id1,id2);
                }
            }
        }

        for(auto x:grid[n-1]) ans=min(ans,x);
        return ans;
    }
};