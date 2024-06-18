class Solution {
public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>job;
        for(int i=0;i<difficulty.size();i++){
            job.push_back({difficulty[i],profit[i]});
        }
        sort(job.begin(),job.end());
        sort(worker.begin(),worker.end());

int maxprofit=0;
int bestprofit=0;
int i=0;

        for(int w:worker){
            while(i<job.size() && job[i].first <= w){
                bestprofit = max(bestprofit,job[i].second);
                ++i;
            }
            maxprofit+=bestprofit;
        }
        return maxprofit;

    }
};