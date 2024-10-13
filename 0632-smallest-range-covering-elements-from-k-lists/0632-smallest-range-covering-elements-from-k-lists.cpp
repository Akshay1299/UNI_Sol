class Helper{
    public:
    int val;
    int i,j;
    Helper(int val,int i,int j){
        this->i=i;
        this->j=j;
        this->val=val;
    }
};
class cmp{
    public:
    bool operator()(Helper* a,Helper* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        vector<pair<int,int>> v;
        priority_queue<Helper*,vector<Helper*>,cmp> pq;
        for(int i=0;i<nums.size();i++){
            Helper* h1=new Helper(nums[i][0],i,0);
            pq.push(h1);
        }
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            v.push_back({top->val,top->i});
            if(top->j+1<nums[top->i].size()){
                Helper* h1=new Helper(nums[top->i][top->j+1],top->i,top->j+1);
                pq.push(h1);
            }
        }
        int i=0,j=0;
        unordered_map<int,int> mp;
        vector<int> ans(2,-1);
        ans[0]=-100000;
        ans[1]=100000;
        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        while(j<v.size()){
            mp[v[j].second]++;
            while(mp.size()==k){
                if(v[j].first-v[i].first<ans[1]-ans[0]){
                    ans[0]=v[i].first;
                    ans[1]=v[j].first;
                }
                mp[v[i].second]--;
                if(mp[v[i].second]==0){
                    mp.erase(v[i].second);
                }
                i++;

            }
            j++;
        }
        return ans;
        
    }
};