class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0;
        for (int n : nums) {
            finalXor ^= n;
        }
        
        int count = 0;
        while (k || finalXor) {
            if ((k & 1) != (finalXor & 1)) {
                count++;
            }
            
            k >>= 1;
            finalXor >>= 1; 
        }
        
        return count;
    }
};