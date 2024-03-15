class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int proL = 1, proR = 1;
        int L = nums.size();
        vector<int> prefix_proR(L, 0);
        vector<int> prefix_proL(L, 0);
        vector<int> ret(L, 0);
        int i = 0, j = L-1;

        while(i<L && j >= 0)
        {
            proR *= nums[j];
            prefix_proR[j] = proR;

            proL *= nums[i];
            prefix_proL[i] = proL;
            i++;
            j--;
        }

        for(int i = 0; i < L; i++)
        {
            if(i == 0)
            {
                ret[i] = prefix_proR[i+1];
            }
            else if(i == L-1)
            {
                ret[i] = prefix_proL[i-1];
            }
            else
            {
                ret[i] = prefix_proL[i-1]*prefix_proR[i+1];
            }
        }
        return ret;
    }
};