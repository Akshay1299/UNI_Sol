class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
       int n= nums.size(); 
       vector<int> xorr(n,0);
       xorr[0]= nums[0];  
       for(int i=1; i<n; i++){
            xorr[i]= nums[i]^xorr[i-1]; 
       } 

       vector<int> ans; 
       for(int i=0; i<n; i++){
          int xorr1= xorr[n-1-i]; 
          int que=0; 
            for(int j=0; j<maximumBit; j++){
                int bit= (xorr1>>j)&1; 
                if(bit==0){
                    que= que | (1<<j); 
                }
            }
            ans.push_back(que); 
       }
       return ans; 
    }
};