class Solution {
public:
    string fractionAddition(string expression) {
        ios_base::sync_with_stdio(0);
        int n = expression.size();
        if(expression[0] != '+' && expression[0] !='-'){
            reverse(expression.begin(), expression.end());
            expression.push_back('+');
            reverse(expression.begin(), expression.end());
            n++;
        }
        vector<int>nums, denoms, signs;
        int i = 0;
        while(i < n){
            if(expression[i] == '+' || expression[i] == '-'){
                signs.push_back((expression[i] == '+') ? 1 : -1);
                i++;
            }
            int val = 0;
            while(i < n && (expression[i] >= '0' && expression[i] <= '9')){
                val = val * 10 + (expression[i] - '0');
                i++;
            }
            nums.push_back(val);
            i++; val = 0;
            while(i < n && (expression[i] >= '0' && expression[i] <= '9')){
                val = val * 10 + (expression[i] - '0');
                i++;
            }
            denoms.push_back(val);
        }
        int den_final = denoms[0];
        for(int i = 1; i < denoms.size(); i++){
            den_final = (den_final * denoms[i]) / __gcd(denoms[i], den_final);
        }
        int num_final = 0;
        for(int i = 0; i < nums.size(); i++){
            num_final += signs[i] * nums[i] * (den_final / denoms[i]);
        }
        int gc = __gcd(abs(num_final), den_final);
        num_final /= gc;
        den_final /= gc;

        return to_string(num_final) + "/" + to_string(den_final);
    }
};