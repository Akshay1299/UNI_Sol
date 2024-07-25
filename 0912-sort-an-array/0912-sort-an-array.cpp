class Solution {
public:

    void Merge(vector<int> &arr, int l , int mid, int r){
        vector<int> merged;
        int p = l;
        int q = mid + 1;
        while(p <= mid && q <= r)
            {
                if(arr[p] < arr[q])
                    merged.push_back(arr[p++]);
                else
                    merged.push_back(arr[q++]);
            }
        while(p <= mid)
            merged.push_back(arr[p++]);
        while(q <= r)
            merged.push_back(arr[q++]);

        int x = l;
        for(int i : merged)
            arr[x++] = i;
    }

    void MergeSort(vector<int> &arr, int l , int r){
        if(l >= r) return;
        int mid = (l + r) / 2;
        MergeSort(arr, l , mid);
        MergeSort(arr, mid + 1 , r);
        Merge(arr , l , mid , r);
    }
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums, 0  , nums.size()-1);
        return nums;   
    }
};