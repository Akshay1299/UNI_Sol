class Solution {
public:
    string firstPalindrome(vector<string>& w) {
        string x="";
        for(int i=0;i<w.size();i++){
            string y="";
            y += w[i];
            int c=1;
            for(int j=0,k=w[i].size()-1;j<k;j++,k--){
                if(y[j]!=y[k])
                {
                    c=0;
                    break;
                }
            }
            if(c){
                x += y;
                return x;
            }
        }
        return x;
    }
};