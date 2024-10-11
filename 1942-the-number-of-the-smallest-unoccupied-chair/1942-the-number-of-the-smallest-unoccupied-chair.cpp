class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int target) {
       int n=times.size();
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > used; 
       priority_queue<int, vector<int>, greater<int>> free;
       vector<int> index(n);
       for(int i=0; i<n; i++){
        index[i]=i;
       }
       sort(index.begin(), index.end(), [&](int a, int b){
        return times[a][0]<times[b][0];
       });
       for (int i = 0; i < n; i++) {
            free.push(i);
        }

       for(int i=0; i<n; i++){
        int in=index[i];
        int arrival=times[in][0];
        int leave=times[in][1];
        while(!used.empty() && used.top().first<=arrival){
            free.push(used.top().second);
            used.pop();
        }
        if (!free.empty()){
        int chair=free.top();
        free.pop();
        used.push({leave, chair});
        if(in==target) return chair;
        }
       }
       return -1;
    }
};