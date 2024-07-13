class Solution {
public:
    static bool sortbysec(const pair<int,int> &a,const pair<int,int> &b ){
        return (a.second<b.second);
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>> indices;
        for(int i=0;i<positions.size();i++) {
            indices.push_back(make_pair(i,positions[i]));
        }
        sort(indices.begin(), indices.end(), sortbysec);
        stack<int> ans;
        int i=0;
        while(i<indices.size())
        {
            if(!ans.empty()){
                auto t= ans.top();

                if(directions[t]=='R' && directions[indices[i].first]=='L'){
                    if(healths[t]>healths[indices[i].first]){
                        healths[t]--;
                        healths[indices[i].first]=0;
                        i++;
                    }
                    else if(healths[t]==healths[indices[i].first]){
                        ans.pop();
                        healths[t]=0;
                        healths[indices[i].first]=0;
                        i++;
                    }
                    else {
                        healths[t]=0;
                        ans.pop();
                        healths[indices[i].first]--;
                    }
                }
                else {
                    ans.push(indices[i].first);
                    i++;
                }

            }
            else {
                ans.push(indices[i].first);
                        i++;
            }
        }

        vector<int> fin;
        for(int p:healths){
            if(p>0)
            fin.push_back(p);
        }
        return fin;    
    }
};