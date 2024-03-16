class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int zeros = 0,ones = 0,ans = 0;

        for(int i = 0; i < nums.size() ; i++){
           if(nums[i]) ones++;
           else zeros++;

           if(zeros == ones) ans = i+1;
           else if(mp.find(zeros - ones) != mp.end()) ans = max(ans,i-mp[zeros - ones] );
           else mp[zeros - ones] = i;
        }
        return ans;
    }
};