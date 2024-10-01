class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k,0);
        for(int num : arr){
            int rem =  ((num%k)+k)%k;
            freq[rem]++;
        }

        for(int i=1;i<k;i++){
             if(freq[i]!=freq[k-i]){
                return false;
             }
        }

        if(freq[0]%2 !=0){
            return false;
        }
        return true;
    }
};