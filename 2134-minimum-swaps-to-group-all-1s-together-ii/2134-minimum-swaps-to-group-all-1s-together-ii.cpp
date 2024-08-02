class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int count1 = 0;  int n = nums.size();

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) count1++;
        }

        if(count1==n || count1==0) return 0;
        int minS = INT_MAX;

        int i=0; int j = 0;  int oneInWindow = 0; 
        while(j<count1){
            if(nums[j]==1){
                oneInWindow++;
            }
            j++;
        }

        while(i<n){
            if(minS > abs(oneInWindow - count1)){
                minS=abs(oneInWindow - count1);
            }

            if(nums[i]==1){
                oneInWindow--;
            }
            i++;

        
            if(nums[j%n]==1) oneInWindow++;
            j++;
        }


        return minS;     
    }
};