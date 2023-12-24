class Solution {
public:
    int minOperations(string s) {
        char j='0',k='1';
        string str1,str2;
        int m=1;

        for(int i=0;i<s.size();i++)
        {
           if(m%2==0)
           {
               str1+=k;
               str2+=j;
           }
           else
           {
               str1+=j;
               str2+=k;
           }
           m++;
        }
        int mini1=0,mini2=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=str1[i])
            {
                mini1++;
            }
            else if(s[i]!=str2[i])
            {
                mini2++;
            }
        }
        int ans=min(mini1,mini2);
        return ans;
    }
};