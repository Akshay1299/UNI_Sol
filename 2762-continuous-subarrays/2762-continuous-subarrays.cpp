class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int curmax = nums[0];
        int curmin = nums[0];
        int j = 0;
        vector<pair<long long ,long long>> v;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-curmax)<=2 && abs(nums[i]-curmin)<=2){
                curmax = max(curmax,nums[i]);
                curmin = min(curmin,nums[i]);
            }
            else{
                v.push_back({j,i-1});
                int k = i;
                curmax = INT_MIN;
                curmin = INT_MAX;
                while(abs(nums[i]-nums[k])<=2)curmin=min(curmin,nums[k]),curmax=max(curmax,nums[k]),k--;
                j = k + 1;  
            }
        }
        v.push_back({j,n-1});
        long long fans = 0;
        for(int i=0;i<v.size();i++){   
            fans += ( (v[i].second-v[i].first)*(v[i].second-v[i].first+1) ) / 2;
            if(i>0 && v[i].first<v[i-1].second){
                fans -= ( (v[i-1].second-v[i].first)*(v[i-1].second-v[i].first+1) ) /2;
            }
        }
        fans += n;
        return fans;
    }
};