class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        
        vector<int> dp(9,0);
            int sum = 1;
        dp[0]= 1;
        dp[1] = 10;
            
            for(int i =2;i<=n;i++){
                dp[i] = (10-i+1)*dp[i-1] + sum;
                sum+=dp[i-1];
            }
      return dp[n];  
      
    }
};