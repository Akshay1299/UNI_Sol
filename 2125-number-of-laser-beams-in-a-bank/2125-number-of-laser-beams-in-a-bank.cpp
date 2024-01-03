class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size()-1, m=bank[0].size()-1;vector<int>cr;
        int count=0;
        for(int i=n;i>=0;i--){
            int c=0;
            for(int j=m;j>=0;j--){
                if(bank[i][j]=='1'){
                    c++;
                }
            }
            if(c>0){
                cr.push_back(c);
            } 
        }
        if(cr.size()<=1){
            return 0;
        }
        else {
            for(int i=cr.size()-1;i>=1;i--){
                count=cr[i]*cr[i-1]+count;
            }
        }
        return count;
    }
};