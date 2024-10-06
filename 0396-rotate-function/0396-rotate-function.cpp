// class Solution {
// public:
//     int maxRotateFunction(vector<int>& nums) {
//         int totalsum=0;
//         int fun_0=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             totalsum=totalsum+nums[i];
//             fun_0=fun_0+i*nums[i];

//         }
//         int maxval=fun_0;
//         int fun_i=fun_0;
//         for(int i=1;i<n;i++){
//             fun_i=fun_i+totalsum-nums[n-i]*n;
//             maxval=max(maxval,fun_i);
//         }
//         return maxval;
        
//     }
// };

// With DP

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            dp[0]+=(i*nums[i]);
         
        } 
        int ans=dp[0];
       
        int ind=n-1;
        for(int i=1;i<nums.size();i++){
            dp[i]=sum+dp[i-1]-(n*nums[ind]);
            ind--;
            ans=max(dp[i],ans);
        }
        return ans;
    }
};