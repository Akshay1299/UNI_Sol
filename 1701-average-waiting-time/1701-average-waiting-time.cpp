class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0.0;
        double finishTime = 0;

        double totalTime = 0;
        for(auto it : customers){
            int start = it[0];
            int dest = it[1];

            if(start > finishTime)
            {
                finishTime = (double)start;
            }

            finishTime += (double)dest;

            totalTime += (double)(finishTime - start);

        }

        return (totalTime)/customers.size();
    }
};