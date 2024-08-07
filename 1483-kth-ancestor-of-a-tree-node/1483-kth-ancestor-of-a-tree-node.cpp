class TreeAncestor {
public:
    vector<vector<int>> up, graph;
    vector<int> height;
    int l, sum;

    void dfs(int u, int p, int h){ 
        height[u] = h;
        up[u][0] = p;
        for(int i = 1; i <= l; i++)
            up[u][i] = up[up[u][i-1]][i-1];

        for(int v : graph[u])
            dfs(v, u, h + 1);
    }

    TreeAncestor(int n, vector<int>& parent) {
        l = ceil(log2(n));
        up.resize(n, vector<int>(l+1, 0));
        graph.resize(n);
        height.resize(n);

        for(int i = 1; i < parent.size(); i++)
            graph[parent[i]].push_back(i);
        dfs(0, 0, 0);
    }
    
    int getKthAncestor(int node, int k) {
        if(k > height[node])
            return -1;
        
        sum = 0;
        for(int i = l; i >= 0; i--){
            if(sum + pow(2, i) <= k){
                sum = sum + pow(2, i);
                node = up[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */