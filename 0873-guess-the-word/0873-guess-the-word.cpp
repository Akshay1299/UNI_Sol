/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    
    vector<string> reducelist(vector<string> &wordlist, string guess, int d) {
        vector<string> reducedlist;
        for (auto &word: wordlist) {
            if (match(word, guess) == d) reducedlist.push_back(word); 
        }
        return reducedlist;
    }
    
    int match(string from, string to) {
        int d = 0, n = from.length();
        for (int i = 0; i < n; i ++) {
            if (from[i] == to[i]) d ++;
        }
        return d;
    }
    
    int wordsRemoved(string guess, string secret, vector<string> &wordList) {
        int d = match(guess, secret);
        int remove = 0;
        for (auto &word: wordList) {
            auto d1 = match(guess, word);
            if (d != d1) remove ++; 
        }
        return remove;
    }
    
    string minimax(vector<string>& wordList) {
        int n = wordList.size();
        map<string, int> count;
        for (auto &word: wordList) count[word] = INT_MAX;
        for (auto &guess: wordList) {
            for (auto &secret: wordList) {
                count[guess] = min(count[guess], wordsRemoved(guess, secret, wordList));       
            }
        }
        int max = INT_MIN;
        string res;
        for (auto &word: wordList) {
            if (count[word] > max) {
                max = count[word];
                res = word;
            }
        }
        return res;
    }
    
    
    void findSecretWord(vector<string>& wordlist, Master& master) {

        auto reducedlist = wordlist;
        
        while (true) {
            auto guess = minimax(reducedlist);
            int d = master.guess(guess);
            if (d == 6) break;
            reducedlist = reducelist(reducedlist, guess, d);
        }
        
    }
};