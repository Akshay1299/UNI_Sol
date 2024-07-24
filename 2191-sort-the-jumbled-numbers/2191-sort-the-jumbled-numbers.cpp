class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto get_map_val = [&mapping](int a){
            string sa = to_string(a);
            string s = "";
            for(auto& v : sa){
                s += to_string(mapping[v - '0']);
            }
            return stoi(s);
        };
        unordered_map<int, int> map_val;
        for(auto& v : nums){
            map_val[v] = get_map_val(v);
        }
        sort(nums.begin(), nums.end(), [&map_val](int a, int b){
            return map_val[a]<map_val[b];
        });
        return nums;
    }
};