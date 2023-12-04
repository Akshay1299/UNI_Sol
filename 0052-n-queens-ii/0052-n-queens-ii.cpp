class Solution {
public:
    bool safe(int *place,int row,int col){
               for(int i=0;i<row;i++){
                   if(place[i]==col) return false;
                   if(abs(row-i)==abs(col-place[i])) return false;
               }
               return true;
    }
    void nqueen(int n,int row,int *place,int *sum){
                  for(int i=0;i<n;i++){
                if(safe(place,row,i)){
                   place[row]=i;
                   if(row==n-1) (*sum)+=1;
                   else nqueen(n,row+1,place,sum);
                }     
                
                
           }
    }
    int totalNQueens(int n) {
        int place[n];
        int sum=0;
nqueen(n,0,place,&sum);
        return sum;
    }
};