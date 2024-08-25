class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths, int node) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            paths.push_back(path);
        } else {
            for (int neighbor : graph[node]) {
                dfs(graph, path, paths, neighbor);
            }
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, path, paths, 0);
        return paths;
    }
};