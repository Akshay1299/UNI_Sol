class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        int countCons = 1;
        for(int i=1; i<k ; i++){
            if(nums[i]-nums[i-1] == 1){
                countCons += 1;
            }
        }
        if(countCons == k){
            ans.push_back(nums[k-1]);
        }
        else{
            ans.push_back(-1);
        }
        for(int i=1 ; i<n-k+1 ; i++){
            if(nums[i]-nums[i-1] == 1){
                countCons -= 1;
            }
            if(nums[i+k-1]-nums[i+k-2] == 1){
                countCons += 1;
            }
            if(countCons == k){
                ans.push_back(nums[i+k-1]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};