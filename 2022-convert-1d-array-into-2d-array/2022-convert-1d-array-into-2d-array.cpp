class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        vector<vector<int>> vec( m , vector<int> (n));

        if( original.size()!=n*m)return {};

        for(int i=0;i<original.size();i++){
            int row=i/n;
            int col=i%n;
            if(row>=0 && row<m && col>=0 && col<n)
            vec[row][col]=original[i];
        }

        for(auto v:vec){
            for(auto i:v)if(i==0)return {};
        }

        return vec;      
    }
};