class Solution {
    public:
    int leastBricks(vector<vector<int>>&wall){
        unordered_map<int, int> mp;
        int maxi = 0;
        for(int i =0; i<wall.size(); i++){
            int line = 0;
            for(int j =0; j<wall[i].size()-1; j++){
                line+=wall[i][j];
                mp[line]++;
                maxi = max(mp[line], maxi);
            }
        }
        return wall.size() - maxi;
    }
};