class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int s = 0, e = nums.size()-1;
        int mid = s+(e-s)/2;
        int ans = -1;
        while(s<=e){
            if(nums[mid]==target){
                ans = mid;
                e = mid -1;
            }
            else if (nums[mid]<target){
                s=mid+1;
            }
            else if (nums[mid]>target){
                e = mid-1;
            }
            
            mid = s+(e-s)/2;
        }
        
         s = 0; 
         e = nums.size()-1;
         mid = s+(e-s)/2;
        int ans2 = -1;
        
        while(s<=e){
            if(nums[mid]==target){
                ans2=mid;
                s = mid+1;
            }
             else if (nums[mid]<target){
                s = mid+1;
            }
            
            else if(nums[mid]>target){
                e = mid-1;
            }
            
           
            
            mid = s+(e-s)/2;
            
        }
        
        vector<int> final;
        final.push_back(ans);
        final.push_back(ans2);
        
        
        return final;
        
        
    }
};