class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();

            vector<int>  LessThanLeft(n);   
            vector<int> GretThanRight(n); 

            vector<int> LessThanRight(n); 
            vector<int>  GretThanLeft(n);
            for(int i=0;i<n;i++){
                int less =0, gret = 0;
                for(int j=0;j<i;j++){
                    if(rating[j]<rating[i]) less++;
                    else 
                       gret++;
                }
                LessThanLeft[i] = less;   
                GretThanLeft[i] = gret;
                 less =0, gret = 0;
                for(int j=i+1;j<n;j++){
                    if(rating[j]<rating[i]) less++;
                    else 
                       gret++;
                }
                LessThanRight[i] = less;   
                GretThanRight[i] = gret;
            }
            int cnt = 0;
            for(int i=0;i<n;i++){
                cnt += LessThanLeft[i]*GretThanRight[i];
                cnt += LessThanRight[i]*GretThanLeft[i];
            }
            return cnt;
    }
};