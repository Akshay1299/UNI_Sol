class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, 
    vector<char>& changed, vector<int>& cost) {
        int n=original.size();

        vector<vector<long long>>arr(26, vector<long long>(26, INT_MAX));

        for(int i=0; i<26; i++){
            arr[i][i]=0;
        }

        for(int i=0; i<n; i++){
            long long val=arr[original[i]-'a'][changed[i]-'a'];
            arr[original[i]-'a'][changed[i]-'a']=min(val, (long long)cost[i]);
        }

        for(int via=0; via<26; via++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    arr[i][j]=min(arr[i][j], arr[i][via]+arr[via][j]);
                }
            }
        }

        long long ans=0;

        int sz=source.length();
        if(sz!=target.size()) return -1;

        for(int i=0; i<sz; i++){
            long long cst=arr[source[i]-'a'][target[i]-'a'];
            if(cst!=INT_MAX){
                ans+=cst;
            }else return -1;
        }
        return ans;
        
    }
};