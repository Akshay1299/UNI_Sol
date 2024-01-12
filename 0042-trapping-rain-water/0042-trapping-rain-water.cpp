class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int res=0;
        int mleft=0,mright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=mleft)mleft=height[left];
                else res+=mleft-height[left];
                left++;
            }
            else{
                if(height[right]>mright)mright=height[right];
                else res+=mright-height[right];
                right--;
            }
        }
        return res;
    }
};