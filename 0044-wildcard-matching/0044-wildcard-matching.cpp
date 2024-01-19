// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         if(p.size() == 0) return s.size() == 0;

//         bool first_match = (s.size() > 0) && (p[0] == s[0] || p[0] == '?' || p[0] == '*');

//         if(p[0] == '*'){
//             return first_match && isMatch(s.substr(1), p) ||
//                 isMatch(s, p.substr(1));
//         }else{
//             return first_match && isMatch(s.substr(1), p.substr(1));
//         }
//     }
// };

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int m = s.size(), n = p.size();
        int last_match = -1, starj = -1;
        
        while(i < m){
            
            if(j < n && (p[j] == s[i] || p[j] == '?')){
                //match one
                i++;
                j++;
            }else if(j < n && p[j] == '*'){
                starj = j;
                last_match = i;
                j++;
            }else if(starj != -1){
                last_match++; 
                i = last_match; //?
                j = starj+1;
            }else{
                return false;
            }
        }
        
        return p.substr(j) == string(p.size()-j, '*');
    }
};