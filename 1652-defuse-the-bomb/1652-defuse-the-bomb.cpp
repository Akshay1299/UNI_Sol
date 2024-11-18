class Solution {
public:
    int element_at(vector<int>& code,int index){
        int n = code.size();
        return code[index%n];
        }

    void sliding_window(vector<int>& code,vector<int>& result,int k,int assign){
        int n = result.size();
        int i=0;
            int summ = 0;
            for(int j=0;j<n+k+1;j++){
                if(j+1>k){
                    result[assign%n] = summ;
                    summ-=element_at(code,i);
                    i++;
                    assign++;
                }
                    summ+=element_at(code,j);

            }
    }
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n,0);
        int assign = n - 1;


        if(k<0) {
            k=-k;
            assign = k;
        }
        sliding_window(code,result,k,assign);
    
        return result;
    }
};