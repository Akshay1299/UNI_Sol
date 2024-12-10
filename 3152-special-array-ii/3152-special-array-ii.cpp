class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); 
        vector<bool>ans;
        vector<int>info(n,0); 
        for (int i=0;i<n;i++){
            if (n==1){
                break; 
            }
            if (i==0){
                if ((nums[i]%2==0 && nums[i+1]%2==0) || (nums[i]%2==1 && nums[i+1]%2==1)){
                    info[i]=2; 
                }
            }
            else if (i==n-1){
                if ((nums[i]%2==0 && nums[i-1]%2==0) || (nums[i]%2==1 && nums[i-1]%2==1)){
                    info[i]=1; 
                }
            }
            else{
                if (nums[i]%2==0){
                    if (nums[i-1]%2==1 && nums[i+1]%2==1){
                        continue;
                    }
                    else{
                        if (nums[i-1]%2==0 && nums[i+1]%2==0){
                            info[i]=4;
                        }
                        else if (nums[i-1]%2==0){
                            info[i]=1; 
                        }
                        else if (nums[i+1]%2==0){
                            info[i]=2; 
                        }
                    }
                }
                if (nums[i]%2==1){
                    if (nums[i-1]%2==0 && nums[i+1]%2==0){
                        continue;
                    }
                    else{
                        if (nums[i-1]%2==1 && nums[i+1]%2==1){
                            info[i]=4;
                        }
                        else if (nums[i-1]%2==1){
                            info[i]=1; 
                        }
                        else if (nums[i+1]%2==1){
                            info[i]=2; 
                        }
                    }
                }
            }
        }
        int curr_sum = 0 ;
        vector<int>sum; 
        for (int i=0;i<n;i++){
            curr_sum += info[i]; 
            sum.push_back(curr_sum); 
        }
        for (int i=0;i<queries.size();i++){
            int first = queries[i][0]; 
            int second = queries[i][1]; 
            int numbers = second - first + 1; 

            int my_sum = sum[second]- sum[first]; 
            
            if (my_sum>3){
                ans.push_back(false); 
                continue ; 
            }

            else if (my_sum==3){
                if (info[first]+info[second]==3){
                    ans.push_back(true); 
                }
                else{
                    ans.push_back(false); 
                }
            }
            else if (my_sum==0){
                ans.push_back(true); 
            }
            else{
                if (info[first]==1 || info[second]==2){
                    ans.push_back(true); 
                }
                else{
                    ans.push_back(false);
                }
            }
        }
        return ans; 
    }
};