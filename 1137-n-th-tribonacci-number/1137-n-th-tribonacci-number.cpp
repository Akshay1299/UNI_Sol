class Solution {
public:
    map<int,int>mp;
    int tri(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        if(mp[n]!=0) return mp[n];
        mp[n]=tri(n-1)+tri(n-2)+tri(n-3);
        return mp[n];
    } 
    int tribonacci(int n) {
        int ans=tri(n);
        return ans;
    }
};