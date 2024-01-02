class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
         int n=nums.size();
         int maxi=-1;
         vector<int>freq(n+1,0);
         for(int i=0;i<n;i++){
             freq[nums[i]]++;
             maxi=max(maxi,freq[nums[i]]);
         } 
          vector<vector<int>>ans(maxi,vector<int>(0));
         for(int i=1;i<=n;i++){
          for(int j=0;j<freq[i];j++){
              ans[j].push_back(i);
          }
         }
         return ans;
        
    }
};