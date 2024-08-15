class Solution {
public:
    string decodeString(string s) {

         stack<char> num;
         stack<char> st;
         string res="";

         for(char c: s){

            if(isdigit(c)) num.push(c);

            else{

                if(c!=']') {
                    if(c=='['){
                        num.push(',');
                    }
                    st.push(c);}

                else{
                    int rep=0,mul=1;;
                    num.pop();
                    while(!num.empty() && num.top()!=','){
                        int n = num.top()-'0';
                         cout << n << endl;
                        rep = rep+n*mul;
                        mul*=10;
                        num.pop();
                    }

                    string s1="";
                    while(!st.empty() && st.top()!='['){
                        s1=st.top() + s1;
                        st.pop();
                    }
                    st.pop();

                    if(st.empty()){
                        
                        for(int i=0;i<rep;i++){
                            res+=s1;
                        }
                    }
                    else{
                        for(int i=0;i<rep;i++){

                            for(int j=0; j<s1.size();j++){
                                st.push(s1[j]);
                            }
                          }
                        
                         }
                 }
             }
         }
         string s1="";
         while(!st.empty()){
            s1 = st.top() +s1;
            st.pop();
         }
         res = res+s1;
         return res;
        
    }
};