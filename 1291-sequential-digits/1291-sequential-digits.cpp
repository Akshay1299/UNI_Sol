class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector< int> temp;
        int it,fix=2;
        for(int i=1;i<=9;i++)
        {
            int ans=i;
            it=fix;
            while(it<=9 && ans<=high)
            {
                ans=(ans*10)+it;
                if(ans<=high && ans>=low)  temp.push_back(ans);

                it++;
            }
            fix++;
        }    
        sort(temp.begin(),temp.end());
        return temp;
    }
};
