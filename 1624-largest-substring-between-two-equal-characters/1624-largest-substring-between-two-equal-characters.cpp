class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> ch;
        int m = -1;
        for(int i=0;i<s.length();i++)
        {
            if(ch.find(s[i]) != ch.end())
            {
                m = max(m,i - ch[s[i]]);
            }else{
                   ch[s[i]] = i;
            }
        }
        if(m != -1)return m-1;
        return m;
    }
};