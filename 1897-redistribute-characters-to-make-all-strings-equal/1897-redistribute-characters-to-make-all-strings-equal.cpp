class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++)
            mp[words[i][j]]++;
        }
        int n=words.size();
        for(auto it:mp){
            if(it.second%n)
            return 0;
        }
        return 1;
    }
};