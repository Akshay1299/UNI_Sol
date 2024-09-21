class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        set<pair<int,int>>st;
        unordered_map<int,int>mp;
        vector<int>v;

        for(auto it : barcodes){
            mp[it]++;
        }

        for(auto it : mp){
            st.insert({it.second,it.first});
        }
        int i=0;
                 
            for(auto it = st.rbegin(); it!=st.rend();it++){
                int cnt = it->first;
                int num = it->second;
                cout<<cnt<<" "<<num<<" "<<i<<endl;                
                while(cnt--){
                    cout<<num<<" "<<i<<endl;
                    if(i>=n){
                        i = 1;
                    }
                    barcodes[i] = num; 
                    i += 2; 
                }
            }
        return barcodes;
    }
};