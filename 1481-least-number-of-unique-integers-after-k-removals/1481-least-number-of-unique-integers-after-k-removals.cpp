class Solution {
    class comp{
        public:
        bool operator()(const pair<int,int>& a,const pair<int,int>&b){
            return a.second>b.second;
        }
    };
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        unordered_map<int,int>freq;
        for(auto val : arr)
            freq[val]++;
        
        for(auto element : freq)
         pq.push(element);

        while(k){
            auto element = pq.top();
            pq.pop();
            element.second--;
            k--;
            if(element.second>0)
              pq.push(element);
        } 
        return pq.size();
    }
};