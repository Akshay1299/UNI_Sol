class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        set<int> s;
        for(int i=0;i<edges[0].size();i++){
            s.insert(edges[0][i]);
        }
        int ans = -1;
        for(int i=1;i<edges.size();i++){
            for(int j=0;j<edges[i].size();j++){
                if(s.find(edges[i][j]) != s.end()){
                    ans = edges[i][j];
                }
            }
        }
        return ans;
    }
};