class Solution {
public:
    int minimizedMaximum(int n, const vector<int>& quantities) {
        int l = 0;
        int r = *max_element(quantities.begin(), quantities.end());
        while(r - l > 1){
            int m = (r + l)/2;
            if(check(quantities, m) > n){
                l = m;
            }else{
                r = m;
            }
        }
        return r;
    }
    
    int check(const vector<int>& quantities, int m){
        int n = 0;
        for(int q: quantities){
            if(q % m == 0){
                n += q/m;
            }else{
                n += q/m + 1;
            }
        }
        return n;
    }
};