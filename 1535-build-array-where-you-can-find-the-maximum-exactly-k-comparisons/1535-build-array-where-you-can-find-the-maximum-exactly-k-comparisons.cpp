class Solution {
public:
#define ll long long
const ll p = 1e9+7;
ll calpow(ll x, ll y, ll p)  { ll res = 1; x = x % p; while (y > 0) {if (y & 1) res = (res * x) % p; y = y >> 1; x = (x * x) % p;}   return res; }
int dp[55][55][101];
ll solve(int n,int i,int k,int m,int M){
    if(k == 0){
        return calpow(m,n-i+1,p)%p;
    }

    if(i > n){
        return 0;
    }
    
    if(dp[i][k][m] != -1)return dp[i][k][m];
   
    ll ans = 0;
    
    for(int j = 1;j <= m;j++){
        ans += solve(n,i+1,k,m,M) %p;

    }

    for(int j = m+1;j <= M;j++){
        ans += solve(n,i+1,k-1,j,M)%p;
    }

    return dp[i][k][m] = ans %p;

}

    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,1,k,0,m);        

    }
};