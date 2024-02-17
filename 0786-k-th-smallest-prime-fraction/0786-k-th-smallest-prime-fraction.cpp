class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& nums1, int k) {
        vector<pair<float,pair<int,int>>> p;

        for(int i=0;i<nums1.size();i++)
        {
            for(int j=nums1.size()-1;j>i;j--)
            {
                
             int a=nums1[i];
             int b=nums1[j];

            p.push_back({(float)a/b,{a,b}});   
            }
        }
        sort(p.begin(),p.end());
        return {p[k-1].second.first,p[k-1].second.second};
    }
};