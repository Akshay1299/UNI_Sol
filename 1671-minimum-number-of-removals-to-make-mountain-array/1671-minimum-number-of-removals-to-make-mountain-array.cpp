class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> lis(n , 0);
        vector<int> lds(n ,0);

        for(int i=0;i<n;i++){
            lis[i] = 1 ;
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] && lis[i] < lis[j]+1){
                    lis[i] = lis[j]+1 ;
                }
            }
        }

        for(int i=n-1 ;i>=0;i--){
            lds[i] = 1 ;
            for(int j=n-1 ; j>i;j--){
                if(nums[i] > nums[j] && lds[i] < lds[j]+1){
                    lds[i] = lds[j]+1 ;
                }
            }
        }

        int ans = 0 ;

        for(int i=1;i<n-1;i++){
            if(lis[i] > 1 && lds[i] > 1){
                ans = max(ans , lis[i]+lds[i]-1);
            }
        }

        return n- ans ;
    }
};