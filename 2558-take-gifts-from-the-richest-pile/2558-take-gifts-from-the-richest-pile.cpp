class Solution {
public:
    void modify(vector<int>& gifts){
        int maxi = INT_MIN;
        int idx = -1;
        for(int i=0;i<gifts.size();i++){
            if(gifts[i] >= maxi){
                maxi = gifts[i];
                idx = i;
            }
        }
        int key = sqrt(maxi);
        gifts[idx] = key;
    }


    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        while(k--){
            modify(gifts);
        }
        for(int i=0;i<gifts.size();i++){
            ans += gifts[i];
        }
        
        return ans;
    }
};