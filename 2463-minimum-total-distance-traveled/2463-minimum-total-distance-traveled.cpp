class Solution {
public:
    vector<vector<long long>>dp;
    int n,m;
    long long recursion(int robots, int factories,vector<int>& robot, vector<int>& fac){
        if(robots==-1 ) return 0LL;
        if(factories==-1) return LLONG_MAX;
        if(dp[robots][factories]!=-1) return dp[robots][factories];
        long long take=LLONG_MAX;
            if(robots>=0 && factories>=0){
                long long res=abs((long long)robot[robots]-fac[factories]);
                long long subres=recursion(robots-1,factories-1,robot,fac);
                if(subres!=LLONG_MAX) take=res+subres;
            }
        long long nottake=recursion(robots,factories-1,robot,fac);
        return dp[robots][factories]=min(take,nottake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int>fac;
        n=robot.size();
        for(int i=0;i<factory.size();i++){
            int number=factory[i][1];
            int position=factory[i][0];
            while(number-->0){
                fac.push_back(position);
            }
        }
        m=fac.size();
        sort(fac.begin(),fac.end());
        sort(robot.begin(),robot.end());
        dp.resize(n+1,vector<long long>(m+1,-1));
        return recursion(n-1,m-1,robot,fac);
    }
};