class Solution {
public:
void shift(string &s)
{
  int j=s.size()-1;
  while(j>=0&&s[j]!='0')
    {
      s[j]='0';
      j--;
    }
    if(j<0)
     s='1'+s;
   else 
     s[j]='1';
     return;
}
    int numSteps(string s) {
        int steps=0;
        while(s.size()>1)
        {
            if(s[s.size()-1]=='1')
              shift(s);
             else
              s.pop_back();
              steps++;
        }
        return steps;
    }
};