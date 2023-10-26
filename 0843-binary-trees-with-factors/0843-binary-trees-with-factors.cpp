class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,unsigned long long>mp;
       long long ans=0;
       int mod=1000000007;
        for(int i=0;i<arr.size();i++)
        {
          mp[arr[i]]=1;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
          for(int j=0;j<=i;j++)
          {
              unsigned long long mul=(unsigned long long)((unsigned long long)arr[i]*(unsigned long long)arr[j]);
              if(mul>(mod-9))
              continue;
              if(mp[mul]>0)
              {
                if(arr[i]==arr[j])
                {
                  mp[mul]=(mp[mul]+((mp[arr[i]]%mod)*(mp[arr[j]]%mod))%mod)%mod;
                }
                else
                {
                  mp[mul]=(mp[mul]+((((mp[arr[i]]%mod)*(mp[arr[j]]%mod))%mod)*2)%mod)%mod;
                }
              }
          }
        }
        for(int i=0;i<arr.size();i++)
        {
          ans=(unsigned long long)((unsigned long long)(ans+mp[arr[i]])%mod);
        }
        return(ans);
    }
};