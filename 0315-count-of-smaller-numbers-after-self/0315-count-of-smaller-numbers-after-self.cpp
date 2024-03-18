class Solution {
public:
    
    void merge(vector<pair<int,int>> &v,vector<int>& ans,int l,int mid,int r){
        vector<pair<int,int>> temp(r-l+1);
        int i=l;
        int j=mid+1;
        int k=0;
        
        // decreasing order sorting
        while(i<=mid && j<=r){
            if(v[i].first>v[j].first){
                ans[v[i].second]+=(r-j+1); //main logic
                temp[k++]=v[i++];
            }else{
                temp[k++]=v[j++];
            }
        }
        
        while(i<=mid){
            temp[k++]=v[i++];
        }
        
        while(j<=r){
            temp[k++]=v[j++];
        }
        
        for(int i=l;i<=r;i++){
            v[i]=temp[i-l];
        }
    }
    
    void mergeSort(vector<pair<int,int>> &v,vector<int>& ans,int l,int r){
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(v,ans,l,mid);
            mergeSort(v,ans,mid+1,r);
            merge(v,ans,l,mid,r);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i].first=nums[i];
            v[i].second=i;
        }
        
        vector<int> ans(n,0);
        mergeSort(v,ans,0,n-1);
        return ans;
    }
};