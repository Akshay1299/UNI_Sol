class Solution {
public:

    bool lim(vector<vector<int>>& grid , int i , int j){
        if(grid[i][j] < 1 || grid[i][j] > 9) return false;
        return true;
    }

    bool check_tri (vector<vector<int>>& grid , int x , int y){
        int rows = -1, cols = -1 ;
        set<int> st;
        int diag1 = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2] ,
                diag2 = grid[x ][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y];
        int cnt = 0;
        for(int i = x ; i < x + 3;i++){
            int rowSum = 0 ,colSum = 0, diagSum = 0;
            for(int j = 0 ; j <  3; j++){
                if(!lim(grid , i , j + y )) return false;
                st.insert(grid[i][j + y]);
                // st.insert(grid[x + j][i]);
                rowSum += grid[i][y + j];
                colSum += grid[x + j][y + cnt];
            }
            cnt++;
            if(rows == -1 && cols == -1){
                rows = rowSum;
                cols = colSum;
            }else {
                if(rows != rowSum || cols != colSum) return false;
            }
        }

        if( st.size() == 9 &&  rows == cols && rows == diag1 && rows == diag2){
            return true;
        }else {
            return false;
        }


    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int ans =0 ;
        for(int i = 0 ; i < n;i++ ){
            for(int j = 0; j < m;j++){
                if(i + 3 <= n  && j + 3 <= m ){
                    if(check_tri(grid , i , j)){
                        ans ++;
                    }
                }

            }
        }

        return ans;

    }
};