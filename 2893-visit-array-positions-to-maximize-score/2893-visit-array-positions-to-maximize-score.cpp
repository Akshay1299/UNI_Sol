class Solution {
public:
    
    #define ll long long
    ll int solve(vector<int>& nums, int idx, int parity, int x, vector<vector<ll int>> &memo){
        int n=nums.size();
        
        if(idx == n) return 0;
        
        if(memo[idx][parity] != -1) return memo[idx][parity];
        
        // skip
        ll int skip = solve(nums,idx+1,parity,x,memo);

        ll int acquire = nums[idx] - (nums[idx]%2 == parity ? 0:x) + solve(nums,idx+1,nums[idx]%2,x,memo);
        
        return memo[idx][parity] = max(skip, acquire);
    }
    
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        vector<vector<ll int>> memo(n,vector<ll int>(2,-1));
        
        return nums[0]+solve(nums,1,nums[0]%2, x, memo);
    }
};