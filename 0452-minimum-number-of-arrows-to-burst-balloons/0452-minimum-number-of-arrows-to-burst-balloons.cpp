class Solution {
public:
    static bool mycompare(vector<int>&v1,vector<int>&v2)
    {
        if(v1[0]==v2[0])
        {
            return v1[1]<v2[1];
        }
        return v1[0]<v2[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),mycompare);
        int count=0;
        int ps=points[0][0];
        int pe=points[0][1];
        int n=points.size();
        for(int i=1;i<points.size();i++)
        {
             int cs=points[i][0];
             int ce=points[i][1];
             if(cs>=ps && cs<=pe)
             {
                ps=min(cs,ps);
                pe=min(ce,pe);
             }
             else{
                count++;
                ps=cs;
                pe=ce;
             }
        }
        count++;
        return count;
    }
};