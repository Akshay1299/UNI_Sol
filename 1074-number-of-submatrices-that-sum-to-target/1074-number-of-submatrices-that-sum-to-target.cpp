class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res=0;
        for(int i=0;i<matrix.size();i++){

            vector<int> v(matrix[i].size(),0);

            for(int ii=i ; ii<matrix.size(); ii++){
                for(int id=0;id<v.size();id++){
                    v[id]+=matrix[ii][id];
                }

                for(int id=0;id<v.size();id++){
                    int cur=0;

                    for(int idx=id ; idx<v.size();idx++){
                        cur+=v[idx];
                        if(cur==target){res++;}
                    }
                }
            }
        }
        return res;
    }
};