class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& arr, int extra) {
        int maxi = 0;
        for(auto i : arr) maxi = max(maxi, i);

        vector<bool> ans;
        for(int i = 0;i < arr.size();i++) ans.push_back(arr[i] + extra >= maxi);
        return ans; 
    }
};