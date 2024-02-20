class Solution{
public:
    int missingNumber(vector<int>& nums){
        int answer = 0;
        for(int i = 0; i <= nums.size(); i++)
        {
            if(i < nums.size())
            {
                answer = answer ^ nums[i] ^ i;
            }else{
                answer = answer ^ i;
            }
        }
        return answer;
    }
};