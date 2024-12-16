class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int min=0;
            for(int i=0;i<nums.size();i++){
                min=nums[min]>nums[i]?i:min;
            }
            nums[min]=nums[min]*multiplier;
        }
        return nums;
    }
};