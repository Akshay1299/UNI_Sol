#define m 1000000007

class Solution {
public:
    int countGoodNumbers(long long n) {
        if(n%2==0){
            return (binaryExp(5,n/2)%m)*(binaryExp(4,n/2)%m)%m;
        }
        return (binaryExp(5,n/2+1)%m)*(binaryExp(4,n/2)%m)%m;
    }
    
    long long binaryExp(long long num,long long pow){
        if(pow==1) return num;
        if(pow==0) return 1;
        long long result=binaryExp(num,pow/2)%m;
        if(pow%2==0) return ((result)*(result))%m;
        else return ((num%m)*(((result)*(result)%m)%m))%m;
    }
};