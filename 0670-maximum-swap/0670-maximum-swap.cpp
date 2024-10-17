class Solution {
public:
    int maximumSwap(int num) {
        string st = to_string(num);
        int n = st.length();
        vector<int>temp(n);
        temp[n-1] = n-1;
        for(int i = n-2; i >= 0; i--) {
            temp[i] = st[i] > st[temp[i+1]] ? i: temp[i+1];
        }
        for(int i = 0; i < n; i++){
            if(st[i] < st[temp[i]]){
                swap(st[i],st[temp[i]]);
                return stoi(st);
            }
        }
        return num;
    }
};