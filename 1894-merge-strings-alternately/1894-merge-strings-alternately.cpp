class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i =0;
        string ans = "";
        int n = word1.length();
        int m = word2.length();
        while(i<n || i<m){
            if(i<n){
                ans = ans+word1[i];
            }
            if(i<m){
                ans = ans+word2[i];
            }
            i++;
        }
        return ans;
    }
};