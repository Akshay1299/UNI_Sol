class Solution {
public:
    static const int N = 1e5;
    int p[N],sz[N];
    int get(int i){
        if(i==p[i]) return i;
        p[i] = get(p[i]);
        return p[i];
    }
    void merge(int x,int y){
        x = get(x);
        y = get(y);
        if(x==y) return;
        if(sz[x]<sz[y]) swap(x,y);
        p[y] = x;
        sz[x]+=sz[y];
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        for(int i=0;i<n;i++){
            p[i]=i;
            sz[i] = 1;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int z = nums[i];
            for(int j=2;j*j<=z;j++){
                if(z%j==0){
                    if(mp.count(j)){
                        merge(i,mp[j]);
                    }
                    else{
                        mp[j] = i;
                    }
                    while(z%j==0){
                        z/=j;
                    }
                }
            }
            if(z>1){
                if(mp.count(z)){
                    merge(i,mp[z]);
                }
                else{
                    mp[z] = i;
                }
            }
        }
        return sz[get(0)]==n;
    }
};