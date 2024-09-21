class Solution {
public:
    string smallestSubsequence(string s) {
        
        unordered_set<char>st;
        stack<char>ds;
        unordered_map<char,int>mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }

        for(int i=0;i<s.size();i++){
            char c = s[i];

            if(st.find(c) == st.end()){
                while(!ds.empty() && c<ds.top() && i<mp[ds.top()]){
                    st.erase(ds.top());
                    ds.pop();
                }
                st.insert(c);
                ds.push(c);
            }
        }
        string ans = "";

        while(!ds.empty()){
            ans+=ds.top();
            ds.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};