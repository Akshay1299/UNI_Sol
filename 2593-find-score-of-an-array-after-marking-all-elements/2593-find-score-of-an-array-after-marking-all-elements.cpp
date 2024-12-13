class Solution {
public:
    long long findScore(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool>marked(n, false);
        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i], i});
        }
        
        long long ans = 0;
        while(!pq.empty())
        {
            int node = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            
            if(marked[index] == false)
            {
                ans += node;
                marked[index] = true;
                
                if(index+1 < n)
                {
                    marked[index+1] = true;
                }
                if(index-1 >= 0)
                {
                    marked[index-1] = true;
                }
            }
        }
        return ans;
    }
};