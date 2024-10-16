class Solution {
public:
int find_max(vector<int>& ele,pair<int,int> prev){
    int ind=-1;
    int temp=INT_MIN;
    for(int i=0;i<ele.size();i++){
        if(i==prev.first && i==prev.second) continue;
        else if(ele[i]>0 && ele[i]>temp) {
            ind=i;
            temp=ele[i];
        }
    }
    return ind;
}
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        pair<int,int>prev={-1,-1};
        vector<int>ele={a,b,c};
        int ind=-1;
        while(ans.size()<a+b+c){
            ind=find_max(ele,prev);
            if(ind==-1) break;
            else{
                char curr='a'+ind;
                ans.push_back(curr);
                ele[ind]-=1;
                prev.first=prev.second;
                prev.second=ind;
            }
        }
        return ans;
    }
};