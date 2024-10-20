class Solution {
private:
    
    bool evalAnd(vector<bool> &v){
      bool ans = true;
      for(auto i: v){
        ans &= i;
        if(!ans)  return false;
      }
      return true;
    }
    
    bool evalOr(vector<bool> &v){
      bool ans = false;
      for(auto i: v){
        ans |= i;
        if(ans) return true;
      }
      return false;
    }
    
    bool evalNot(vector<bool> &v){
      return !v[0];
    }
    
    bool parseExpr(string &expr,int &pos){
      char op = expr[pos];
      pos += 2;
      vector<bool> operands;
      while(expr[pos] != ')'){
        if(expr[pos] == '&' || expr[pos] == '|' || expr[pos] == '!'){
          operands.push_back(parseExpr(expr,pos));
          pos++;
        }else if(expr[pos] == 't' || expr[pos] == 'f'){
          bool var = expr[pos] == 't';
          operands.push_back(var);
          pos++;
        }
        if(expr[pos] == ','){
          pos++;
        }
      }
      if(op == '&'){
        return evalAnd(operands);
      }
      if(op == '|') return evalOr(operands);
      if(op == '!')   return evalNot(operands);
      return false;
    }
    
public:
    bool parseBoolExpr(string expression) {
      int pos = 0;
      return parseExpr(expression,pos);
    }
};