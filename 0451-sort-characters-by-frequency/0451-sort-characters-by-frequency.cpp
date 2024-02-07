class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto ch: s)
            mp[ch]++;
        
        vector<pair<int,char>> freq;
        for(auto it: mp){
            freq.push_back({it.second, it.first});
        }
        sort(freq.begin(), freq.end(), greater<>());

        string ans = "";
        int n = freq.size();

        for(int i=0; i<n; i++){
            ans += string(freq[i].first, freq[i].second);
        }
        return ans;
    }
};