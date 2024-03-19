class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        vector<int> map(26,0);
        int relax=0;
        int sum=0;
        for(int i=0;i<tasks.size();i++) map[tasks[i]-'A']++;
        vector<int>available;
        for(int i=0;i<map.size();i++){
            if(map[i])available.push_back(map[i]);
            sum+=map[i];
        }
        sort(available.begin(),available.end());
        reverse(available.begin(),available.end());
        int n=available.size();
        relax=(available[0]-1)*k;
        for(int i=1;i<n && relax>0;i++){
            relax-=min(available[i],available[0]-1);
        }
        return sum+max(0,relax);
    }
};