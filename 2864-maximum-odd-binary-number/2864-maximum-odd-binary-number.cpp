class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int i,j=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='1'){
                swap(s[i],s[j]);
                j++;
            }
        }
        swap(s[j-1],s[s.size()-1]);
        return s;
    }
};