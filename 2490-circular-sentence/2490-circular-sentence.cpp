class Solution {
public:
    bool isCircularSentence(string sentence) {
        int i;
        for(i=0;i<sentence.size();i++){
            if(sentence[i]==' ' && (i+1)<sentence.size() && sentence[i-1]!=sentence[i+1]){
               return false;
            }
        }

        if(sentence[i-1]!=sentence[0])return false;

        return true;
    }
};