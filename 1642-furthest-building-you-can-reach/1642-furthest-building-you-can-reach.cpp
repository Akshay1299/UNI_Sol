class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int sum = 0;
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<n-1;i++){
            int diff = heights[i+1]-heights[i];
            if(diff<=0) continue;
            if(pq.size()<ladders){
                pq.push(diff);
                continue;
            }
            if(!pq.empty()){
                int mini = pq.top();
                if(mini<=diff){
                    sum+=mini;
                    pq.pop();
                    pq.push(diff);
                }
                else{
                    sum+=diff;
                }
            }
            else{
                sum+=diff;
            }
            if(sum>bricks){
                return i;
            } 

        }
        return n-1;
    }
};