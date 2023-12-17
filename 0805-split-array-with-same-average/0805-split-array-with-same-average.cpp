class Solution {
public:
    vector<vector<bool>> memo;
    vector<vector<int>> grey;
    bool dp(int i,vector<int>& arr,int sum,int n,int tsum)
    {
        if(i>=arr.size())
            if(n>0&&n<arr.size()&&(float)sum/n==(float)(tsum-sum)/(arr.size()-n))
                return true;
            else return false;
        else if(grey[i][sum]&(1<<n))
            return memo[i][sum];
        else
        {
            grey[i][sum]|=1<<n;
            return memo[i][sum]=memo[i][sum]||dp(i+1,arr,sum+arr[i],n+1,tsum)||dp(i+1,arr,sum,n,tsum);
        }
    }        
    bool splitArraySameAverage(vector<int>& A) 
    {
        int tsum=0;
        for(int x:A)
            tsum+=x;
        memo.resize(A.size(),vector<bool>(tsum+1,0));
        grey.resize(A.size(),vector<int>(tsum+1,0));
        return dp(0,A,0,0,tsum);
    }
};