class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int, int>> adjList[n];
        meetings.push_back({0, firstPerson, 0});
        for(int i = 0; i < meetings.size(); i++) {
            adjList[meetings[i][0]].push_back({meetings[i][1], meetings[i][2]});
            adjList[meetings[i][1]].push_back({meetings[i][0], meetings[i][2]});
        }
        vector<int> minSharedTime(n, INT_MAX);
        minSharedTime[0] = 0;
        queue<pair<int, int>> Queue;
        Queue.push({0, 0});
        while(!Queue.empty()) {
            int sz = Queue.size();
            for(int i = 0; i < sz; i++) {
                auto [u, uTime] = Queue.front();
                Queue.pop();
                for(auto [v, w]: adjList[u]) {
                    if(uTime <= w && minSharedTime[v] > w) {
                        Queue.push({v, w});
                        minSharedTime[v] = w; 
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(minSharedTime[i] != INT_MAX) 
                ans.push_back(i);
        }
        return ans;
    }
};