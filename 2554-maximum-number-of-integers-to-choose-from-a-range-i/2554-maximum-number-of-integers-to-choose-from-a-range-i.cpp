class Solution {
    bool bs(vector<int> &v,int x,int r){
        int l=0,m;
        while(l<=r){
            m=l+(r-l)/2;
            if(v[m]==x) return true;
            else if(v[m]<x)l=m+1;
            else r=m-1;
        }
        return false;
    }
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(),banned.end());
        int res=0,sum=0,size=banned.size()-1;
        for(int i=1;i<=n;i++){
            if(!bs(banned,i,size)){
                if(sum+i<=maxSum)sum+=i,res++;
                else break;
            }
        }
        return res;
    }
};