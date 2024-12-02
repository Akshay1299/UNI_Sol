class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size();//size of the string
        istringstream s(sentence);
        int index=0;
        string word;
        while(s>>word){
            if(word.find(searchWord)==0){
                return index+1;
            }
            index++;
        }
        return -1;
    }
};