class Solution {
public:
    bool func(string s1,string s2){
        vector<string> s11,s22;
        stringstream ss(s1),ss1(s2);
        string x,y;
        while(ss>>x) s11.push_back(x);
        while(ss1>>y) s22.push_back(y);
        int n1=s11.size(),n2=s22.size(),i=0,j=n1-1,j1=n2-1;
        while(i<n1 && i<n2 && s11[i]==s22[i]) i++;
        while(j>=0 && s11[j]==s22[j1]) j--,j1--;
        if(i>j) return 1;
        return 0;
    }
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length()>s2.length()) return func(s2,s1);
        return func(s1,s2);
    }
};