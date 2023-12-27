class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0, current=-1;
        for(int i=0; i < colors.size()-1; i++){
            if(colors[i]==colors[i+1]){
                if(current==-1) current = neededTime[i];
                cost += min(current, neededTime[i+1]);
                current = max(current, neededTime[i+1]);
            }
            else current = -1;
        }
        return cost;
    }
};