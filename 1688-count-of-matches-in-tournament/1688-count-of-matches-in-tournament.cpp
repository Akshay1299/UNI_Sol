class Solution {
public:
    int numberOfMatches(int n) {
        int count=0, adv=0;
        while(n>1){
            if(n%2==0){
            count+=n/2;
            adv=n/2;
            }else {count+=(n-1)/2;
                 adv=((n-1)/2)+1;}
           n=adv;
        }return count;
    }
};