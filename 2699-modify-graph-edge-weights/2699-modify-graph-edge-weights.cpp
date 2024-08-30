class Solution {
public:
    vector<int> calculateShortestDistance(int n, vector<pair<int,int>> adj[], int src) {
        vector<int> dis(n, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dis[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;

                if (dis[adjNode] > dist + weight) {
                    dis[adjNode] = dist + weight;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }

        return dis;
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int des, int target) {
        vector<pair<int,int>> adj[n];

        for (auto& it : edges) {
            if (it[2] != -1) {
                adj[it[0]].push_back({it[1], it[2]});
                adj[it[1]].push_back({it[0], it[2]});
            }
        }

        vector<int> dis = calculateShortestDistance(n, adj, src);

        if (dis[des] < target) {
            return {};
        }

        if (dis[des] == target) {
            for (auto& edge : edges) {
                if (edge[2] == -1) {
                    edge[2] = 1e9;  
                }
            }
            return edges;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][2] == -1) {
                edges[i][2] = 1;
                adj[edges[i][0]].push_back({edges[i][1], 1});
                adj[edges[i][1]].push_back({edges[i][0], 1});

                dis = calculateShortestDistance(n, adj, src);

                if (dis[des] <= target) {
                    edges[i][2] += target - dis[des];
                    for (int j = i + 1; j < edges.size(); j++) {
                        if (edges[j][2] == -1) {
                            edges[j][2] = 1e9;
                        }
                    }
                    return edges;
                }
            }
        }

        return {};
    }
};
