class Solution {
public:
void fun(string &s , int x){
    for(int i=x;i<=s.length();++i){
        if(s[i]=='('){s[i]='!';fun(s, i+1);}
        else if(s[i]==')'){
            reverse(s.begin()+x , s.begin()+i);
            s[i]='#';
            return;
        }
    }
}
    string reverseParentheses(string s) {
        fun(s , 0);
        string ans="";
        for(auto x:s){
            if(x=='!'|| x=='#')continue;
            ans+=x;
        }
        // reverse(ans.begin() , ans.end());
        return ans;
    }
};