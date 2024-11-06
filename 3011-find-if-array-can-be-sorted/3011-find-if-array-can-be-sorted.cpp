class Solution {
public:
    int countSetBits(int num) {
        int setBits = 0;
        for(int i=0;i<=8;i++) {
            if(num & (1<<i)) setBits ++;
        }
        return setBits;
    }

    bool canSortArray(vector<int>& nums) {
        
        vector<int>maxNumWithSetBits(9, 0);

        for(auto num: nums) {
            int setBits = countSetBits(num);
            for(int i=1;i<=8;i++) {
                if(setBits != i) {
                    if(maxNumWithSetBits[i] > num) return false;
                }
                maxNumWithSetBits[setBits] = max(maxNumWithSetBits[setBits], num);
            }
        }
        return true;
    }
};