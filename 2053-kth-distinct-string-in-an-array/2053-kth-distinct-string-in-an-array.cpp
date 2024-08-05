class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            if(mp[arr[i]]==1)
            {
                ans++;
                if(ans==k)
                {
                    return arr[i];
                }
            }
        }
        return "";
    }
};