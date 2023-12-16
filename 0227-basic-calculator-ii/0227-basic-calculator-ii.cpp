class Solution {
public:
    int dfs(string &s, int &i){
        int num = 0;
        vector<int> stack;
        char sign = '+';
        s += " ";

        while (i < s.length()){
            if (isdigit(s[i])){
                num = num*10 + (s[i] - '0');
            }

            if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || i == s.length()-1){
                if (sign == '+'){
                    stack.push_back(num);
                }

                if (sign == '-'){
                    stack.push_back(-num);
                }

                if (sign == '*'){
                    int v = stack.back()*num;
                    stack.pop_back();
                    stack.push_back(v);
                }

                if (sign == '/'){
                    int v = stack.back()/num;
                    stack.pop_back();
                    stack.push_back(v);
                }

                num = 0;
                sign = s[i];
            }

            i++;
        }

        return accumulate(stack.begin(),stack.end(),0);
    }

    int calculate(string s) {
        int i = 0;
        return dfs(s,i);
    }
};
