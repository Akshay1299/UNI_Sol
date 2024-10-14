class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for(long a:nums){
            maxHeap.push(a);
        }
        long long score = 0;
        while(k>0){
            long long num = maxHeap.top();
            maxHeap.pop();
            if(num>0){
                score = score + num;
                long long modify = ceil((double)num/3);
                maxHeap.push(modify);
                k--;
            }
        }
        return score;
    }
};