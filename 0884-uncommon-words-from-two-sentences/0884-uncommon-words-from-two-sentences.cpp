class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map <string,int> count;
        string temp="";
        for(int i=0;i<s1.size();i++){
            if(i==s1.size()-1){
                temp+=s1[i];
                count[temp]++;
                temp="";
            }
            else if(s1[i]==' '){
                count[temp]++;
                temp="";
            }
            else
                temp+=s1[i];
        }

        for(int i=0;i<s2.size();i++){
            if(i==s2.size()-1){
                temp+=s2[i];
                count[temp]++;
                temp="";
            }
            else if(s2[i]==' '){
                count[temp]++;
                temp="";
            }
            else
                temp+=s2[i];
        }

        vector<string> ans;
        for(auto x : count){
            if(x.second == 1)
                ans.push_back(x.first);
        }
        return ans;
    }
};