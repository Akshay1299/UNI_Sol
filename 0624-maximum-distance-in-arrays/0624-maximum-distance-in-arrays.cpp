class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDistance = 0;
        int smallestNum = arrays[0][0];
        int biggestNum = arrays[0].back();
        
        for(int i=1;i<arrays.size();i++){
            maxDistance = max(maxDistance,abs(arrays[i].back()-smallestNum));
            maxDistance  = max(maxDistance,abs(biggestNum-arrays[i][0]));
            smallestNum = min(smallestNum,arrays[i][0]);
            biggestNum = max(biggestNum,arrays[i].back());
        }
        return maxDistance;
    }
};