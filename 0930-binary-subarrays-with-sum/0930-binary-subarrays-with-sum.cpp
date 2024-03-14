class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int res=0;
        int windowSum=0;
        int i=0,j=0;
        int zerosCount=0;
        while(j<n){
            windowSum += nums[j];

            while(i<j && (nums[i]==0 || windowSum > goal)){
                if(nums[i]==0)
                    zerosCount++;
                else 
                    zerosCount=0;
                
                windowSum -= nums[i];
                i++;
            }
            if(windowSum==goal)
                res+= 1 + zerosCount;

            j++;
        }
        return res;
    }
};