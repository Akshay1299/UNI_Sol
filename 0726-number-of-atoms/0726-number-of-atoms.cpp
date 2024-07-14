class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string,int>>st;
        int i=0;
        while(i<formula.size()){
            if(formula[i]=='('){
                st.push({"(",-1});
                i++;
            }
            
            else if(formula[i]==')'){
                i++;
                string snum="";
                while(isdigit(formula[i])){
                    snum+=formula[i];
                    i++;
                }
                int sno;

                if(snum=="")
                    sno=1;
                else  
                    sno=stoi(snum);

                vector<pair<string,int>>v;
                while(st.top().first!="("){
                    string stname=st.top().first;
                    int stno=st.top().second*sno;
                    st.pop();
                    v.push_back({stname,stno});
                }

                st.pop();

                for(int i=0;i<v.size();i++){
                    st.push(v[i]);
                }
            }
            else{
                string s="";
                s+=formula[i];
                i=i+1;
                while(islower(formula[i])){
                    s+=formula[i];
                    i++;
                }

                string snum="";
                while(isdigit(formula[i])){
                    snum+=formula[i];
                    i++;
                }
                if(snum=="")
                    snum="1";
                int sno=stoi(snum);

                st.push({s,sno});
            }           
        }
        map<string,int>mp;
            while(!st.empty()){
                mp[st.top().first]+=st.top().second;
                st.pop();
            }

            string ans="";

            for(auto i:mp){
                ans+=i.first;
                if(i.second==1)
                    continue;
                ans+=to_string(i.second);
            }
        return ans;
    }
};