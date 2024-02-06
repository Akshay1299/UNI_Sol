class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>>res;
       map<string,stack<string>>maps;
        for(auto &k:strs){
            string aux=k;
            sort(aux.begin(),aux.end());
            maps[aux].push(k);
        }
        for(auto k:maps){
            vector<string>aux;
            while(k.second.empty()==false){
                aux.push_back(k.second.top());
                k.second.pop();
            }
            res.push_back(aux);
        }


       return res;
    }
};