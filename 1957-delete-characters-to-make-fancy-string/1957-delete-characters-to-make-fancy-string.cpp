class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int p=s[0];
        int cnt=1;
        ans+=p;
        for(int i=1;i<s.size();i++)
        { 
                  if(s[i]==p)
                  {
                    cnt++;
                  }
                  else if(s[i]!=p)
                  {
                    p=s[i];
                    cnt=1;
                  }
                  if(cnt<3)
                  {ans+=s[i];

                  }  
        }
        return ans;
    }
};