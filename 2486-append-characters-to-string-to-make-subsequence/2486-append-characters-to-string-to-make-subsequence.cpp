class Solution {
public:
    int appendCharacters(string s, string t) {
        int l = t.length();
        int i = 0, j = 0;
        while (s[j] != 0){
            if (t[i]==s[j]){
                i++;
                j++;
            } 
            else {
                j++;
            }   
        }
        return l-i;
        
    }
};