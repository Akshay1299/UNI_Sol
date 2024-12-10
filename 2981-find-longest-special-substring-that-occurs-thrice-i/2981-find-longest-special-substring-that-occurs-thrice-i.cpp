class Solution {
public:
bool is_valid(string temp){
    bool ans=true;
    for(int i=0;i<temp.size()-1;i++){
        if(temp[i]!=temp[i+1]){
            ans=false;
            break;
        }
    }
    return ans;
}

    int maximumLength(string s) {
        unordered_map<string,int>fre;
            for(int i=0;i<s.size();i++){
                string temp="";
                for(int k=0;k<s.size();k++){
                    if(i+k>=s.size()) break;
                    temp.push_back(s[i+k]);
                fre[temp]++;
                }
            }
        
        int ans=INT_MIN;
        for(auto it=fre.begin();it!=fre.end();it++){
            if(it->second>=3 ) {
                if(!is_valid(it->first)) continue;
                ans = max(ans, static_cast<int>(it->first.size()));
            }
        }
        if(ans==INT_MIN) ans=-1;
        return ans;
    }
};