class Solution {
public:
    int passThePillow(int n, int time) {
        int q = time/(n-1);
        int rem = time%(n-1);

        if(q%2 == 0){
            return 1+rem;
        }
        return n-rem;
    }
};