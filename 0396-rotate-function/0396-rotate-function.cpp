class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int totalsum=0;
        int fun_0=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            totalsum=totalsum+nums[i];
            fun_0=fun_0+i*nums[i];

        }
        int maxval=fun_0;
        int fun_i=fun_0;
        for(int i=1;i<n;i++){
            fun_i=fun_i+totalsum-nums[n-i]*n;
            maxval=max(maxval,fun_i);
        }
        return maxval;
        
    }
};