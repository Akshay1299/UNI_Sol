class Solution {
public:
    int ans=0;
    void check(int i, int j, string& s){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--,j++;
            ans++;
        }
        return;
    }
    int countSubstrings(string s) {
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            check(i,i,s);
            check(i,i+1,s);
        }
        return ans;
    }
};