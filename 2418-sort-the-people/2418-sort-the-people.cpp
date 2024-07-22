class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        std::map<int , std::string, std::greater<>> hashmap;

        for (int i = 0; i < names.size(); ++i)
        hashmap[heights[i]] = names[i];

        names = {};

        for (auto i : hashmap)
        names.push_back(i.second);
        
        return names;
    }
};