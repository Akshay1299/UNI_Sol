class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> map;
        vector<int> res;
        for(int i=0; i<arr1.size(); i++){
            map[arr1[i]]++;
        }
        for(int i=0; i<arr2.size(); i++){
            while(map[arr2[i]]){
                res.push_back(arr2[i]);
                map[arr2[i]]--;
            }
            map.erase(arr2[i]);
        }
        for(auto i=map.begin(); i!=map.end(); i++){
            while(i->second){
                res.push_back(i->first);
                i->second--;
            }
        }
        return res;
    }
};