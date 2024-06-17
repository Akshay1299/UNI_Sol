class Solution {
public:
    int sqr(int c){
        int s = 1;
        int e = c;
        int ans = 1;
        while(s<=e){
            long long int mid = s+(e-s)/2;
            if(mid*mid<=c){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
    bool judgeSquareSum(int c) {
        long long int s = 0;
        long long int e = sqr(c);
        cout<<e;
        while(s<=e){
            if(s*s+e*e==c)return true;
            if(s*s+e*e>c)e-=1;
            else s+=1;
        }
        return false;
    }
};