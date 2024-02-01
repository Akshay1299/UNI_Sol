class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        int nn=nums.size()/3;
        vector<vector<int>>ans(nn,vector<int>(3,-1));
        sort(nums.begin(),nums.end());
        int f=0;
        int op=0;
        for(int i=2;i<n;i+=3)
        {
            int pre=i-2;
            if((nums[i]-nums[pre])<=k)
            {
               ans[op][0]=nums[i-2];
               ans[op][1]=nums[i-1];
               ans[op][2]=nums[i];
               op++;

            }
            else
            {
                f=1;
                break;
            }
        }
        if(f==1)
        {
        ans.clear();
        }
        return ans;
    }
};