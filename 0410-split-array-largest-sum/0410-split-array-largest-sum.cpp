class Solution {
public:

    bool possible(vector<int> nums,int k,int subArrSum){

        int count=0,nsub=1;
        for(int i=0;i<nums.size();i++){
            if(count+nums[i]>subArrSum){
                nsub++;count=nums[i];
            }
            else count+=nums[i];
        }
        return (nsub<=k);

    }


    int splitArray(vector<int>& nums, int k) {
        
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(auto x:nums) high+=x;

        while(low<=high){
            int mid = (low+high)/2;
            if(possible(nums,k,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};