class Solution 
{
public:
    string makeGood(string s) 
    {
        string ss;
        
        for (char c : s)
            if (!ss.empty() && (ss.back() ^ c) == 32)
                ss.pop_back();
            else
                ss.push_back(c);
        
        return ss;
    }
};