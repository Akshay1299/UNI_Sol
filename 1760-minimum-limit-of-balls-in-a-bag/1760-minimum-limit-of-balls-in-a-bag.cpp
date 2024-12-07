class Solution {
public:
    bool isFeasible(vector<int> &nums,int &mx,int curr){

        int cnt=0;
        for(auto it : nums){
            if (it%curr==0) cnt+=it/curr;
            else cnt+=it/curr+1;
        }
        return cnt<=mx;
    }
    int minimumSize(vector<int>& nums, int mo) {
        int mx=nums.size()+mo;
        int l=1,r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            if (isFeasible(nums,mx,mid)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};