class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        ios_base::sync_with_stdio(0);
        vector<vector<int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
        vector<pair<int,int>>pts(6);
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                pts[board[i][j]] = {i,j};
            }
        }
        map<vector<pair<int,int>>,int>mp;
        mp[pts]++;
        queue<pair<vector<pair<int,int>>,int>>q;
        vector<pair<int,int>>ans = {{1,2},{0,0},{0,1},{0,2},{1,0},{1,1}};
        q.push({pts,0});
        while(!q.empty()){
            vector<pair<int,int>>p(6);
            p = q.front().first;
            int moves = q.front().second;
            q.pop();
            if(p == ans){
                return moves;
            }
            vector<vector<int>>brd(2,vector<int>(3,0));
            for(int k = 0; k < 6; k++){
                brd[p[k].first][p[k].second] = k;
            }
            for(int j = 0; j < 4; j++){
                int dx = p[0].first + dir[j][0],dy = p[0].second + dir[j][1];
                if(dx < 0 || dy < 0 || dx == 2 || dy == 3){
                    continue;
                }
                else{
                    swap(brd[p[0].first][p[0].second],brd[dx][dy]);
                    vector<pair<int,int>>temp(6);
                    for(int i = 0; i < 2; i++){
                        for(int j = 0; j < 3; j++){
                            temp[brd[i][j]] = {i,j};
                        }
                    }
                    if(mp.find(temp) == mp.end()){
                        q.push({temp,moves+1});
                        mp[temp]++;
                    }
                    swap(brd[p[0].first][p[0].second],brd[dx][dy]);
                }
            }
        }
        return -1;
    }
};