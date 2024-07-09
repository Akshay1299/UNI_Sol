class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool result=false;
        for(int i=0;i<ransomNote.length();i++){
            if(magazine.length()>0){
            for(int j=0;j<magazine.length();j++){
                if (ransomNote[i]==magazine[j]){
                    magazine.erase(magazine.begin()+j);
                    result=true;
                    break;
                }
                else
                result=false;
            }
            }
            else
            result=false;
            if(result!=true)
            return false;
        }
     
        return true;
    }
};