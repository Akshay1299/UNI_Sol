class Solution {
public:
    int dp[305][305];
    int f(int i , int j , vector<int>&v){

        if(i>j) return 0;

        int maxi=INT_MIN;


        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i ; k<=j ; k++){

            int ans= v[k]*v[i-1]*v[j+1] +f(i,k-1 , v) +f(k+1 , j , v);
            maxi = max(maxi , ans);
        }

        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        
        memset(dp , -1 , sizeof(dp));
        int n=nums.size();
        vector<int>v;
        v.push_back(1);

        for( int i=0 ; i<n ; i++){
            v.push_back(nums[i]);
        }

        v.push_back(1);

    return f(1,n ,v  );
        
    }
};