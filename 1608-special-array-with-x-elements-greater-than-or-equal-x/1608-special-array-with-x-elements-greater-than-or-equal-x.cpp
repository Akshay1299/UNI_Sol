class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c = 0;
        int val = -1;
        for(int i=1; i<=nums.size(); i++){
            c=0;
            for(int j=0; j<nums.size(); j++){
                if(i<=nums[j]){
                    c++;
                }
            }
            if(i==c){
                val = i;
                break;
            }
        }
        return val;
    }
};