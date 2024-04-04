class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        stack<char> store;
        int maxDepth = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                store.push(s[i]);
                if(store.size() > maxDepth){
                    maxDepth = store.size();
                }
            }
            else if(s[i] == ')'){
                store.pop();
            }
        }
        return maxDepth;
    }
};