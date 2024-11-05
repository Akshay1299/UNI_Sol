class Solution {
public:
    int minChanges(string s) {
        int count=0;
        int i=0;
        while(i<s.size()){
        if(s[i]!=s[i+1]){count++;}
        i+=2;
        }
        return count;
    }
};