class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0;
        int j=skill.size()-1;
        unordered_set<int>st;
        while(i<j)
        {
           long long sum=0;
           sum+=skill[i];
           sum+=skill[j];
           st.insert(sum);
           i++;
           j--;
        }
        if(st.size()>1) return -1;
        else
        {
            long long summ=0;
             i=0;
             j=skill.size()-1;
             while(i<j)
             {
                long long pp=skill[i];
                long long ss=skill[j];
                long long product=pp*ss;
                 summ+=product;
                 i++;
                 j--;
             }
 return summ;
        }
       return -1;
    }
};