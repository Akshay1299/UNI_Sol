class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) 
    {
        unordered_set<string> s; 
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            int count=0;
            string str="";
            
            for(int j=i;j<n;j++)
            {
                if(nums[j]%p==0)
                    count++;
                
                if(count>k)
                    break;
                
                str+=to_string(nums[j])+"->";
                s.insert(str);
            }
        }
        return s.size();
    }
};