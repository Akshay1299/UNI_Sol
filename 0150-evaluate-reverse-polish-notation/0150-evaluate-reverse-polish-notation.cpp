class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        for(auto it : tokens){
            if(it == "+" || it == "-" || it == "*" || it == "/"){
                int x = sta.top();
                sta.pop();
                int y = sta.top();
                sta.pop();
                if(it == "+")
                    sta.push(y + x);
                else if(it == "-")
                    sta.push(y - x);
                else if(it == "*")
                    sta.push(y * x);
                else 
                    sta.push(y / x);
            }
            else
                sta.push(stoi(it));
        }
        return sta.top();
    }
};