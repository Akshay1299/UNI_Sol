class Solution {
public:
    vector<int> getAnswer(map<int,int> &track, int maxPoint){
        vector<int> ans;
        ans.push_back(maxPoint);
        while(track[maxPoint]!=-1){
            ans.push_back(track[maxPoint]);
            maxPoint = track[maxPoint];
        }
        return ans;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        map<int, int> fq;
        map<int,int> track;
        int ans = 1;
        int n = nums.size();
    
        for(int i=0;i<n;i++){
            fq[nums[i]] += 1;
            track[nums[i]] = -1;
        } 

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(fq[nums[j]]>=fq[nums[i]]){
                         fq[nums[i]] = max(fq[nums[j]]+1, fq[nums[i]]);
                        track[nums[i]] = nums[j];   
                    }
                }
            }
        }

        map<int,int> :: iterator itr;
        int maxPoint = -1;
        for(itr=fq.begin();itr!=fq.end();itr++){
            if(itr->second>=ans){
                maxPoint = itr->first;
                ans = itr->second;

            }
        }

        if(ans==1) return {nums[0]};

        return getAnswer(track, maxPoint);
    }
};