class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int max1=INT_MIN;
        int k=0;
    for(int i=0;i<nums.size();i++){
          mp[nums[i]]++;
          max1=max(max1,mp[nums[i]]);
         
    }
     for(auto p:mp){
         if(p.second==max1){
          k+=max1;   
         }
     }
     return k;
    }
};